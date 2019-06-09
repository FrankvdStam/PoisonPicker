#include "color_wheel.h"


namespace poison_picker {
	namespace animations
	{
		color_wheel::color_wheel(devices::i_led_controller* led_controller, devices::i_dashboard* dashboard)
			: i_animation(led_controller, dashboard) {}

		void color_wheel::update(unsigned long miliseconds) 
		{
			//m_led_controller->set_segment(0, rgb(255, 0   , 0  ));
			//m_led_controller->set_segment(1, rgb(0  , 255 , 0  ));
			//m_led_controller->set_segment(2, rgb(0  , 0   , 255));
			//m_led_controller->show();


			int potmeter_value = m_dashboard->potmeter_value();
			if (potmeter_value != m_potmeter_previous_value) 
			{
				m_potmeter_previous_value = potmeter_value;
				int position = helper::numeric_map(potmeter_value, 50, 870, MIN_MAP_GRAPH, MAX_MAP_GRAPH);
				rgb color = get_color_from_graph(position);
				m_led_controller->set_all_leds(color);
				m_led_controller->show();
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