#include "i_animation.h"

#define MIN_MAP_GRAPH 0
#define MAX_MAP_GRAPH 767

#define R_OFFSET 0
#define G_OFFSET 255
#define B_OFFSET 511

namespace poison_picker
{
	namespace animations
	{
		class cylon : public i_animation
		{			
		public:
			cylon(i_led_controller* led_controller, i_dashboard* dashboard) : i_animation(led_controller, dashboard)
			{

			}


			void activate(unsigned long milliseconds)
			{
				m_dashboard->display_clear();
				m_dashboard->display_write("cylon");
				m_dashboard->display_set_cursor(0, 1);
				m_dashboard->display_write("interval: ");
			}

			void update(unsigned long milliseconds)
			{
				update_interval(milliseconds);
				
				if (m_previous_milliseconds + m_interval < milliseconds)
				{
					m_previous_milliseconds = milliseconds;

					if (m_color_position > 767)
					{
						m_color_position = 0;
					}
					m_led_controller->set_led(m_position, get_color_from_graph(m_color_position++));
					move();
					m_led_controller->show();
				}				
			}

			void deactivate(unsigned long milliseconds)
			{
				m_dashboard->display_clear();
			}

			void move()
			{
				if (m_direction)
				{
					m_position++;
				}
				else
				{
					m_position--;
				}

				if (m_position == 0)
				{
					m_direction = true;
				}
				if (m_position >= m_led_controller->get_number_of_leds() - 1) 
				{
					m_direction = false;
				}
			}

		private:
			unsigned int m_color_position = 0;
			unsigned int m_position = 0;
			bool m_direction = true;

			long m_interval = 35;
			unsigned long m_previous_milliseconds = 0;

			void update_interval(unsigned long milliseconds)
			{
				long rotary_encoder_change = m_dashboard->rotary_encoder_change();
				if (rotary_encoder_change != 0)
				{
					m_interval += rotary_encoder_change;

					if (m_interval < 0)
					{
						m_interval = 0;
					}

					m_dashboard->display_set_cursor(10, 1);
					m_dashboard->display_write("       ");
					m_dashboard->display_set_cursor(10, 1);
					m_dashboard->display_write(m_interval);
				}
			}

			/*
			We can generate 3 phases of this graph:
			(y: r/g/b)
			255 /|\   |    |
			   / | \  |    |
			  /  |  \ |    |
			0/   |   \|____|
			0   255  511  767 (x: potmeter position)

			if(x < 256)
			{
				y = x;
			}
			else if (x > 255 && x < 512)
			{
				y = 256 - x;
			}
			else{
				y = 0;
			}

			We offset each color to get 3 phases, thats the rgb values. 
			*/
			unsigned char map_graph_color(long position, long offset)
			{
				//loop pos around 0-767
				position = position + offset > MAX_MAP_GRAPH ? (position + offset) - MAX_MAP_GRAPH : position + offset;

				//generate the graph
				if (position <= 255)
				{
					return static_cast<unsigned char>(position);
				}

				if (position >= 256 && position <= 511)
				{
					return static_cast<unsigned char>(255 - (position - 256));
				}

				return 0;
			}

			rgb get_color_from_graph(long position)
			{
				unsigned char r = map_graph_color(position, R_OFFSET);
				unsigned char g = map_graph_color(position, G_OFFSET);
				unsigned char b = map_graph_color(position, B_OFFSET);

				return rgb(r, g, b);
			}

		};
	}
}