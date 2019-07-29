#pragma once
#include "i_animation.h"
#include "../random.h"
#include "../colors.h"

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
			void reflow();
			vector3i calculate_approach_vector(vector3i a, vector3i b, int steps);

			unsigned char m_flow_increment = 1;
			long m_flow_interval = 35;
			unsigned long m_previous_milliseconds = 0;

			const int steps = 20;
			int* m_current_steps;
			rgb* m_current_colors;
			rgb* m_random_colors;
		};
	}
}
