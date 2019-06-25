#pragma once
#include "devices/i_led_controller.h"
#include "devices/i_dashboard.h"
#include "animations/i_animation.h"
#include "animations/animations.h"

using poison_picker::devices::i_dashboard;
using poison_picker::devices::i_led_controller;
using poison_picker::animations::i_animation;

namespace poison_picker
{
	class animator 
	{
	public:
		animator(i_led_controller* led_controller, i_dashboard* dashboard, i_animation** animations, unsigned int size);
		~animator();
		void update(unsigned long milliseconds);

	private:
		i_led_controller* m_led_controller;
		i_dashboard* m_dashboard;


		bool m_can_toggle_animation = true;
		i_animation** m_animations;
		unsigned int m_animations_size = 0;
		unsigned int m_current_animation = 0;
	};
}

/*
void println(char* str);


void poison_picker::println(char* str)
{
	Serial.println(str);
}

extern void poison_picker::println();
*/