#pragma once
#include "i_animation.h"
#include "../random.h"

namespace poison_picker
{
	namespace animations
	{
		class rinald : public i_animation
		{
		public:
			rinald(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long milliseconds);
			void update(unsigned long milliseconds);
			void deactivate(unsigned long milliseconds);
		private:
			int m_index = 0;
			unsigned long m_delay = 250;
			unsigned long m_previous_milliseconds = 250;
		};
	}

}



