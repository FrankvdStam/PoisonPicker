#pragma once
#include "../devices/i_led_controller.h"
#include "../devices/i_dashboard.h"


namespace poison_picker {
	namespace animations
	{
		class i_animation
		{
		public:
			i_animation(devices::i_led_controller* led_controller, devices::i_dashboard* dashboard) : led_controller(led_controller), dashboard(dashboard) {}

			virtual void update(unsigned long miliseconds) = 0;

		protected:
			devices::i_led_controller* led_controller;
			devices::i_dashboard* dashboard;
		};
	}
}