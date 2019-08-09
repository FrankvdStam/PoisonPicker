#include "tictactoe.h"

//Not my best work in terms of tidiness. Cleanup required.

namespace poison_picker
{
	namespace animations
	{
		tictactoe::tictactoe(i_led_controller* led_controller, i_dashboard* dashboard) : i_animation(led_controller, dashboard)
		{
			m_board = new unsigned char[m_led_controller->get_number_of_segments()];

			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++)
			{
				m_board[i] = 0;
			}
		}

		void tictactoe::activate(unsigned long milliseconds)
		{
			m_led_controller->clear();
			m_led_controller->show();

			m_dashboard->display_clear();
			m_dashboard->display_write("tic tac toe");

			reset();
		}

		void tictactoe::update(unsigned long milliseconds)
		{

			if (m_state_playing)
			{
				m_led_controller->clear();

				display_board();
				cursor();
				select_segment();

				m_led_controller->show();

				if (has_win_condition(win_condition, &m_win_color))
				{
					//goto win state with timing setup
					m_state_playing = false;
					m_previous_milliseconds = milliseconds;
					m_led_controller->clear();

					if (i_logger::available())
					{
						i_logger::get().print("win\n");

						for (unsigned int i = 0; i < 3; i++)
						{
							int a = win_condition[i];
							i_logger::get().print(win_condition[i]);
							i_logger::get().print("\n");
						}
					}

					return;//if we win and place the last piece simultaniously, the game will recognize this as no moves left unless we skip that function on this cycle.
				}

				if (no_moves_left())
				{
					reset();
				}
			}
			else
			{
				if (m_previous_milliseconds + m_interval < milliseconds)
				{
					if (win_toggles > 0)
					{
						m_previous_milliseconds = milliseconds;
						for (unsigned int i = 0; i < m_win_condition_size; i++)
						{
							m_led_controller->set_segment(win_condition[i], win_toggle ? m_win_color : rgb(0, 0, 0));
						}
						win_toggle = !win_toggle;
						win_toggles--;

						m_led_controller->show();
					}
					else
					{
						reset();
					}
				}
			}

			m_led_controller->show();
		}

		void tictactoe::deactivate(unsigned long milliseconds)
		{
			reset();
		}

		//move and draw the cursor
		void tictactoe::cursor()
		{
			m_cursor += m_dashboard->rotary_encoder_change();

			if (m_cursor >= (int)m_led_controller->get_number_of_segments())
			{
				m_cursor = 0;
			}
			if (m_cursor < 0)
			{
				m_cursor = m_led_controller->get_number_of_segments() - 1;
			}

			m_led_controller->set_segment(m_cursor, m_cursor_color);
		}

		//click and remember segments
		void tictactoe::select_segment()
		{
			//int x = 0, y = 0;
			//serpent(m_cursor, &x, &y);

			if (m_dashboard->button_pressed_switch())
			{

			}

			if (m_dashboard->button_pressed_switch() && m_board[m_cursor] == 0)
			{
				m_board[m_cursor] = turn ? 1 : 2;
				turn = !turn;
			}
		}

		void tictactoe::display_board()
		{
			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++)
			{
				if (m_board[i] != 0)
				{
					m_led_controller->set_segment(i, m_board[i] == 1 ? m_red : m_green);
				}
			}
		}

		//reset the state of the board
		void tictactoe::reset()
		{
			m_cursor = 0;
			turn = true;
			m_state_playing = true;
			win_toggles = 6;
			win_toggle = true;

			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++)
			{
				m_board[i] = 0;
			}
		}

		bool tictactoe::has_win_condition(unsigned char* win_condition, rgb* win_color)
		{
			for (unsigned int condition = 0; condition < m_win_conditions_count; condition++)
			{
				bool win = true;
				int color = 0;
				for (unsigned int i = 0; i < m_win_condition_size; i++)
				{
					int index = m_win_conditions[condition][i];

					if (m_board[index] == 0)
					{
						win = false;
						break;
					}
					else
					{
						if (i == 0)
						{
							color = m_board[index];
						}
						else
						{
							if (color != m_board[index])
							{
								win = false;
								break;
							}
						}
					}
				}

				if (win)
				{
					//copy the win codition 
					for (unsigned int i = 0; i < m_win_condition_size; i++)
					{
						win_condition[i] = m_win_conditions[condition][i];
					}
					*win_color = color == 1 ? m_red : m_green;
					return true;
				}
			}
			return false;
		}
	}
}