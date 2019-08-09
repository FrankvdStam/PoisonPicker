#pragma once
#include "i_animation.h"

namespace poison_picker
{
	namespace animations
	{
		class tictactoe : public i_animation
		{
		public:
			tictactoe(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long milliseconds);

			void update(unsigned long milliseconds);

			void deactivate(unsigned long milliseconds);

			bool no_moves_left()
			{
				for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++)
				{
					if (m_board[i] == 0)
					{
						return false;
					}
				}
				return true;
			}

		private:
			void cursor();
			void select_segment();
			void display_board();
			void reset();
			bool has_win_condition(unsigned char* win_condition, rgb* win_color);
			
			
			int m_cursor = 0;
			const rgb m_cursor_color = rgb(255, 255, 255);

			const rgb m_red   = rgb(255, 0, 0);
			const rgb m_green = rgb(0, 255, 0);
			
			bool turn = true;

			unsigned char* m_board;
			bool m_state_playing = true;
			unsigned char win_condition[3] = {0,0,0};

			long m_interval = 300;
			unsigned long m_previous_milliseconds = 0;
			unsigned char win_toggles = 6;
			bool win_toggle = true;
			rgb m_win_color = rgb(0,0,0);

			static const unsigned int m_win_conditions_count = 8;
			static const unsigned int m_win_condition_size = 3;
			
			/*
			0 1 2 
			5 4 3
			6 7 8
			*/
			
			unsigned char m_win_conditions[m_win_conditions_count][m_win_condition_size] = {
				//horizontal
				{0, 1, 2},
				{5, 4, 3},
				{6, 7, 8},
				//vertical
				{0, 5, 6},
				{1, 4, 7},
				{2, 3, 8},
				//diagonal
				{0, 4, 8},
				{2, 4, 6},
			};


		};
	}
}