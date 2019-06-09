#include "color_wheel.h"

namespace poison_picker {
	namespace animations
	{
		color_wheel::color_wheel(devices::i_led_controller* led_controller, devices::i_dashboard* dashboard)
			: i_animation(led_controller, dashboard) {}

		void color_wheel::update(unsigned long miliseconds) 
		{

		}
		/*
		int map_graph(int position, int offset)
		{
			return position + offset > MAX_MAP_GRAPH ? (position + offset) - MAX_MAP_GRAPH : position + offset;
		}*/

	}
}