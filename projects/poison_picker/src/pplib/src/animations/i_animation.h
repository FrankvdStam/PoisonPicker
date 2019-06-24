#pragma once
#include "../devices/i_led_controller.h"
#include "../devices/i_dashboard.h"

using poison_picker::devices::i_led_controller;
using poison_picker::devices::i_dashboard;
using poison_picker::rgb;

namespace poison_picker {
	namespace animations
	{
		class i_animation
		{
		public:
			i_animation(devices::i_led_controller* led_controller, devices::i_dashboard* dashboard) : m_led_controller(led_controller), m_dashboard(dashboard) {}

			virtual void activate(unsigned long miliseconds) = 0;
			virtual void update  (unsigned long miliseconds) = 0;
			virtual void deactivate(unsigned long miliseconds) = 0;

		protected:
			devices::i_led_controller* m_led_controller;
			devices::i_dashboard* m_dashboard;
		};
	}
}