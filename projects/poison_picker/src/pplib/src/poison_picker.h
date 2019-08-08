#pragma once
#include "devices/i_led_controller.h"
#include "devices/i_dashboard.h"
#include "animations/i_animation.h"

//#define POISON_PICKER_DIAGNOSTICS

using poison_picker::devices::i_dashboard;
using poison_picker::devices::i_led_controller;
using poison_picker::animations::i_animation;

namespace poison_picker
{
	enum class state {
		disabled = 0,
		animations,
		randomizing
	};

	class poison_picker 
	{
	public:
		poison_picker(i_led_controller* led_controller, i_dashboard* dashboard, i_animation* randomize_animation, i_animation** animations, unsigned int size);
		~poison_picker();
		void update(unsigned long milliseconds);

	private:
		void run_animations(unsigned long milliseconds);
		void run_disabled(unsigned long milliseconds);
		void run_randomize(unsigned long milliseconds);

		i_led_controller* m_led_controller;
		i_dashboard* m_dashboard;

		state m_state = state::disabled;
		bool m_can_toggle_state = true;

		bool m_can_toggle_animation = true;
		i_animation** m_animations;
		unsigned int m_animations_size = 0;
		unsigned int m_current_animation = 0;


		unsigned long m_randomize_milliseconds = 0;
		unsigned long m_randomize_interval = 10000;
		i_animation* m_randomize_animation;

#ifdef POISON_PICKER_DIAGNOSTICS
		unsigned long m_diagnostic_update_count = 0;
		unsigned long m_diagnostic_interval = 1000;
		unsigned long m_diagnostic_previous_milliseconds = 0;
#endif
	};
}