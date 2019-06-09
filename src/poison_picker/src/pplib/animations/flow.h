#pragma once
#include "i_animation.h"


namespace poison_picker 
{
	namespace animations
	{
		class flow : public i_animation
		{
		public:
			flow(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long miliseconds);
			void update(unsigned long miliseconds);
			void deactivate(unsigned long miliseconds);
		};
	}

}



