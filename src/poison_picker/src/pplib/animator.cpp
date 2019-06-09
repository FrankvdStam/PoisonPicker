#include "animator.h"

namespace poison_picker
{
	animator::animator(i_led_controller* led_controller, i_dashboard* dashboard, i_animation** animations, unsigned int size)
		: m_led_controller(led_controller), m_dashboard(dashboard), m_animations(animations), m_animations_size(size)
	{
		//Potential undefined behavior when there are no animations.. No exception on arduino.
		//m_current_animation = animations[0];
		//m_current_animation->activate(0);

		m_animations[m_current_animation]->activate(0);
	}

	animator::~animator()
	{
		delete m_led_controller;
		delete m_dashboard;
		delete[] m_animations;
	}
	
	void animator::update(unsigned long miliseconds)
	{
		//get_serial()->println("update in animator");

		m_dashboard->update();
		if (m_dashboard->button_pressed_toggle_state() && m_can_toggle_animation)
		{
			m_can_toggle_animation = false;

			
			m_animations[m_current_animation]->deactivate(miliseconds);
			m_current_animation++;
			
			if (m_current_animation >= m_animations_size)
			{
				m_current_animation = 0;
			}
			m_animations[m_current_animation]->activate(miliseconds);
		}

		if (!m_dashboard->button_pressed_toggle_state()) 
		{
			m_can_toggle_animation = true;
		}

		m_animations[m_current_animation]->update(miliseconds);
	}
}