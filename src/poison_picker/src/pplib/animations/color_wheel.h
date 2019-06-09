#pragma once
#include "i_animation.h"
#include "../rgb.h"
#include "../helper.h"

namespace poison_picker 
{
	namespace animations
	{
		#define MIN_MAP_GRAPH 0
		#define MAX_MAP_GRAPH 767

		#define R_OFFSET 0
		#define G_OFFSET 255
		#define B_OFFSET 511

		class color_wheel : public i_animation {
		public:
			color_wheel(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long miliseconds);
			void update(unsigned long miliseconds);
			void deactivate(unsigned long miliseconds);

		private:
			rgb get_color_from_graph(int position);
			int map_graph_color(int position, int offset);

			int m_potmeter_previous_value = 0;
		};
	}
}