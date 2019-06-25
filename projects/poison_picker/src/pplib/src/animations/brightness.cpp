#include "brightness.h"
#include "../i_logger.h"

namespace poison_picker {
	namespace animations
	{
		brightness::brightness(i_led_controller* led_controller, i_dashboard* dashboard)
			: i_animation(led_controller, dashboard) {}

		void brightness::activate(unsigned long miliseconds)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("brightness");
			m_dashboard->display_set_cursor(0, 1);
			m_dashboard->display_write("value:");
			m_led_controller->set_all_leds(rgb(0, 255, 0));
		}

		void brightness::update(unsigned long miliseconds)
		{
			int rotary_encoder_change = m_dashboard->rotary_encoder_change();

			if (rotary_encoder_change != 0) 
			{
				//make sure we don't overflow our brightness

				if (m_brightness + rotary_encoder_change > 255) 
				{
					m_brightness = 255;
				}
				else if (m_brightness + rotary_encoder_change < 0)
				{
					m_brightness = 0;
				}
				else 
				{
					m_brightness += rotary_encoder_change;
				}

				m_dashboard->display_set_cursor(7, 1);
				m_dashboard->display_write("     ");
				int digits = helper::amount_of_digits(m_brightness);
				m_dashboard->display_set_cursor(10 - digits, 1);
				m_dashboard->display_write(m_brightness);

				m_led_controller->set_brightness(m_brightness);
				m_led_controller->show();
			}
		}

		void brightness::deactivate(unsigned long miliseconds) {}
	}
}