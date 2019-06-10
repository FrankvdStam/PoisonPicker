#include "color_wheel.h"
#include "../debug.h"

namespace poison_picker {
	namespace animations
	{
		color_wheel::color_wheel(i_led_controller* led_controller, i_dashboard* dashboard)
			: i_animation(led_controller, dashboard) {}
		
		void color_wheel::activate(unsigned long miliseconds)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("Color wheel\n");
		}

		void color_wheel::update(unsigned long miliseconds) 
		{			
			
			int potmeter_value = m_dashboard->potmeter_value();
			
			if (potmeter_value != m_potmeter_previous_value) 
			{
				m_potmeter_previous_value = potmeter_value;
				int position = helper::numeric_map(potmeter_value, 20, 925, MIN_MAP_GRAPH, MAX_MAP_GRAPH);

				rgb color = get_color_from_graph(position);

				m_led_controller->set_all_leds(color);
				m_led_controller->show();
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
		int color_wheel::map_graph_color(int position, int offset)
		{
			//loop position around, phases can loop around
			position = position + offset > MAX_MAP_GRAPH ? (position + offset) - MAX_MAP_GRAPH : position + offset;

			//get graph value
			int y = 0;
			if (position < 256)
			{
				y = position;
			}
			else if (position > 255 && position < 512)
			{
				y = 256 - position;
			}
			else {
				y = 0;
			}
			return y;
		}

		rgb color_wheel::get_color_from_graph(int position)
		{
			int r = map_graph_color(position, R_OFFSET);
			int g = map_graph_color(position, G_OFFSET);
			int b = map_graph_color(position, B_OFFSET);

			return rgb(r, g, b);
		}
	}
}