#pragma once
#include "i_animation.h"
#include "../helper.h"

namespace poison_picker {
	namespace animations
	{
		class brightness : public i_animation
		{
		public:

			brightness(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long miliseconds);
			void update(unsigned long miliseconds);
			void deactivate(unsigned long miliseconds);

		private:
			unsigned char m_brightness = 100;
		};
	}
}

