#pragma once
#include "i_animation.h"
#include "../random.h"

namespace poison_picker 
{
	namespace animations
	{
		class flow : public i_animation
		{
		public:
			flow(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long milliseconds);
			void update(unsigned long milliseconds);
			void deactivate(unsigned long milliseconds);
		private:
			unsigned char approach(unsigned char source, unsigned char destination, unsigned char increment);
			rgb get_random_rgb();

			unsigned char m_flow_increment = 1;

			rgb* m_current_colors;
			rgb* m_random_colors;
		};
	}

}



