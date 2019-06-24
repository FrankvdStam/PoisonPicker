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
			int potmeter_value = m_dashboard->potmeter_value();

			if (potmeter_value != m_potmeter_previous_value)
			{
				m_potmeter_previous_value = potmeter_value;
				int bri = helper::numeric_map(potmeter_value, 0, 1023, 0, 255);
				
				//Display the brightness on the display, removing the previous iteration
				m_dashboard->display_set_cursor(7, 1);
				m_dashboard->display_write("     ");//erase previous data
							
				m_led_controller->set_brightness(bri);
				m_led_controller->show();
			}
		}

		void brightness::deactivate(unsigned long miliseconds) {}
	}
}