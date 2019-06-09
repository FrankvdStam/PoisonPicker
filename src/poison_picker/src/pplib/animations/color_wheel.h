#pragma once
#include "i_animation.h"

namespace poison_picker {
	namespace animations
	{
		#define MIN_MAP_GRAPH 0
		#define MAX_MAP_GRAPH 767

		#define R_OFFSET 0
		#define G_OFFSET 255
		#define B_OFFSET 511

		class color_wheel : public i_animation {
		public:
			color_wheel(devices::i_led_controller* led_controller, devices::i_dashboard* dashboard);

			void update(unsigned long miliseconds);
		};
	}
}