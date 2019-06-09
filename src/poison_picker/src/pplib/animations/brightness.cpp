#include "brightness.h"
#include "../debug.h"

namespace poison_picker {
	namespace animations
	{
		brightness::brightness(i_led_controller* led_controller, i_dashboard* dashboard)
			: i_animation(led_controller, dashboard) {}

		void brightness::activate(unsigned long miliseconds)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("brightness\n");
		}

		void brightness::update(unsigned long miliseconds)
		{
			int potmeter_value = m_dashboard->potmeter_value();

			if (potmeter_value != m_potmeter_previous_value)
			{
				m_potmeter_previous_value = potmeter_value;
				int bri = helper::numeric_map(potmeter_value, 20, 925, 0, 255);

				if(bri < 0){
					bri = 0;
				}
				if (bri > 255) {
					bri = 255;
				}

				HardwareSerial* serial = get_serial();
				serial->print(bri);
				serial->print('\n');

				m_led_controller->set_brightness(bri);
				m_led_controller->show();
			}
		}

		void brightness::deactivate(unsigned long miliseconds) {}
	}
}