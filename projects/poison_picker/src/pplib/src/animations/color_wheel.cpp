#include "color_wheel.h"

namespace poison_picker {
	namespace animations
	{
		color_wheel::color_wheel(i_led_controller* led_controller, i_dashboard* dashboard)
			: i_animation(led_controller, dashboard) {}
		
		void color_wheel::activate(unsigned long miliseconds)
		{
			rgb color = get_color_from_graph(m_position);
						
			display_rgb(color);

			m_led_controller->set_all_leds(color);
			m_led_controller->show();
		}

		void color_wheel::display_rgb(rgb color)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("Color wheel");

			m_dashboard->display_set_cursor(0, 1);
			m_dashboard->display_write("r: ");
			m_dashboard->display_write(color.r);

			m_dashboard->display_set_cursor(0, 2);
			m_dashboard->display_write("g: ");
			m_dashboard->display_write(color.g);

			m_dashboard->display_set_cursor(0, 3);
			m_dashboard->display_write("b: ");
			m_dashboard->display_write(color.b);
		}

		void color_wheel::update(unsigned long miliseconds) 
		{			
			long rotary_encoder_change = m_dashboard->rotary_encoder_change() * m_rotary_encoder_multiplier;

			if (rotary_encoder_change != 0)
			{
				m_position = helper::approach_looparound(m_position, rotary_encoder_change, MIN_MAP_GRAPH, MAX_MAP_GRAPH);
				rgb color = get_color_from_graph(m_position);

				m_led_controller->set_all_leds(color);
				m_led_controller->show();

				helper::log_rgb(color, true);
				display_rgb(color);
			}
		}
		
		void color_wheel::deactivate(unsigned long miliseconds) {}

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

		We offset each color to get 3 phases, thats the rgb values. */
		unsigned char color_wheel::map_graph_color(long position, long offset)
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

		rgb color_wheel::get_color_from_graph(long position)
		{
			unsigned char r = map_graph_color(position, R_OFFSET);
			unsigned char g = map_graph_color(position, G_OFFSET);
			unsigned char b = map_graph_color(position, B_OFFSET);
			
			return rgb(r, g, b);
		}
	}
}