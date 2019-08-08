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
			void display_rgb(rgb color);
			rgb get_color_from_graph(long position);
			unsigned char map_graph_color(long position, long offset);

			const long m_rotary_encoder_multiplier = 4;
			long m_position = 0;
		};
	}
}