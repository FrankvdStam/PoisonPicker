#pragma once
#include "i_animation.h"
#include "../helper.h"

namespace poison_picker
{
	namespace animations
	{
		class randomize : public i_animation
		{
		public:
			randomize(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long milliseconds);
			void update(unsigned long milliseconds);
			void deactivate(unsigned long milliseconds);
		
		private:
			unsigned long m_previous_milliseconds = 0;
			unsigned long m_interval = 1000;
			bool* m_leds_enabled;
			int m_to_disable = 0;
		};
	}
}
