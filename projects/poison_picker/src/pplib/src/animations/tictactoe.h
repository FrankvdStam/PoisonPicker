#pragma once
#include "i_animation.h"

namespace poison_picker
{
	namespace animations
	{
		class tictactoe : public i_animation
		{
		public:
			tictactoe(i_led_controller* led_controller, i_dashboard* dashboard) : i_animation(led_controller, dashboard)
			{
			}

			void activate(unsigned long milliseconds)
			{
				m_dashboard->display_clear();
				m_dashboard->display_write("tic tac toe");
			}

			void update(unsigned long milliseconds)
			{

			}

			void deactivate(unsigned long milliseconds)
			{

			}

		};
	}
}