#include "poison_picker.h"

namespace poison_picker
{
	poison_picker::poison_picker(i_led_controller* led_controller, i_dashboard* dashboard, i_animation* randomize_animation, i_animation** animations, unsigned int size)
		: m_led_controller(led_controller), m_dashboard(dashboard), m_randomize_animation(randomize_animation), m_animations(animations), m_animations_size(size)
	{
		//Potential undefined behavior when there are no animations.. No exception on arduino.
		//m_current_animation = animations[0];
		//m_current_animation->activate(0);

		m_animations[m_current_animation]->activate(0);
	}

	poison_picker::~poison_picker()
	{
		delete m_led_controller;
		delete m_dashboard;
		delete[] m_animations;
	}

	void poison_picker::update(unsigned long milliseconds)
	{
		m_dashboard->update(milliseconds);
		switch (m_state)
		{
		case state::disabled:
			run_disabled(milliseconds);
			break;
		case state::animations:
			run_animations(milliseconds);
			break;
		case state::randomizing:
			run_randomize(milliseconds);
			break;
		}
	}

	void poison_picker::run_disabled(unsigned long milliseconds)
	{
		//Wait for keypress and go to animation state
		if (m_dashboard->button_pressed_key())
		{
			m_state = state::animations;
			m_animations[m_current_animation]->activate(milliseconds);
		}
		else
		{
			m_led_controller->set_all_leds(rgb(0, 0, 0));
			m_led_controller->show();

			m_dashboard->display_clear();
			m_dashboard->display_write("disabled");
		}
	}

	void poison_picker::run_animations(unsigned long milliseconds)
	{
		if (m_dashboard->button_pressed_randomize())
		{
			m_animations[m_current_animation]->deactivate(milliseconds);

			m_state = state::randomizing;
			m_randomize_animation->activate(milliseconds);
			m_randomize_milliseconds = milliseconds;

			return;//don't allow the current animation to update.
		}

		//Return to disabled state whenever the key is pressed
		if (m_can_toggle_state && m_dashboard->button_pressed_key())
		{
			m_state = state::disabled;
		}

		if (m_dashboard->button_pressed_toggle_state() && m_can_toggle_animation)
		{
			m_can_toggle_animation = false;


			m_animations[m_current_animation]->deactivate(milliseconds);
			m_current_animation++;

			if (m_current_animation >= m_animations_size)
			{
				m_current_animation = 0;
			}
			m_animations[m_current_animation]->activate(milliseconds);
		}

		if (!m_dashboard->button_pressed_toggle_state())
		{
			m_can_toggle_animation = true;
		}

		m_animations[m_current_animation]->update(milliseconds);

#ifdef POISON_PICKER_DIAGNOSTICS
		m_diagnostic_update_count++;

		if (m_diagnostic_previous_milliseconds + m_diagnostic_interval < milliseconds)
		{
			long time = milliseconds - m_diagnostic_previous_milliseconds;
			m_diagnostic_previous_milliseconds = milliseconds;

			if (i_logger::available()) {
				i_logger& logger = i_logger::get();
				logger.print("fps: ");
				logger.print(m_diagnostic_update_count);
				logger.print(" - ");
				logger.print(time);
				logger.println("");
			}

			m_diagnostic_update_count = 0;
		}
#endif
	}

	void poison_picker::run_randomize(unsigned long milliseconds)
	{
		if (m_randomize_milliseconds + m_randomize_interval < milliseconds)
		{
			m_state = state::animations;
			m_randomize_animation->deactivate(milliseconds);
			m_animations[m_current_animation]->activate(milliseconds);
			return;
		}

		m_randomize_animation->update(milliseconds);
	}
}