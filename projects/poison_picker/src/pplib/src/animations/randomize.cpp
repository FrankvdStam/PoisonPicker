#include "randomize.h"
#include "../random.h"

namespace poison_picker 
{
	namespace animations
	{
		randomize::randomize(i_led_controller* led_controller, i_dashboard* dashboard) : i_animation(led_controller, dashboard) 
		{
			m_leds_enabled = new bool[m_led_controller->get_number_of_segments()];			
		}

		void randomize::activate(unsigned long milliseconds)
		{
			m_previous_milliseconds = milliseconds;

			//reset display
			m_dashboard->display_clear();
			m_dashboard->display_write("randomize");

			//reset state
			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++)
			{
				m_leds_enabled[i] = true;
			}
			m_to_disable = m_led_controller->get_number_of_segments() - 1;
			
			//set leds to random colors
			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++) {
				m_led_controller->set_segment(i, colors::get_random_color());
			}
			m_led_controller->show();
		}

		void randomize::update(unsigned long milliseconds)
		{
			if (m_to_disable > 0 && m_previous_milliseconds + m_interval < milliseconds)
			{
				m_previous_milliseconds = milliseconds;

				//turn 1 segment off
				long r = random(0, m_led_controller->get_number_of_segments());
				while(!m_leds_enabled[r])
				{
					r = random(0, m_led_controller->get_number_of_segments());
				}
				m_leds_enabled[r] = false;
				m_led_controller->set_segment(r, rgb(0, 0, 0));
				m_led_controller->show();

				m_to_disable--;
			}
		}

		void randomize::deactivate(unsigned long milliseconds)
		{
			m_dashboard->display_clear();
			m_led_controller->clear();
			m_led_controller->show();
		}
	}
}