#include "rinald.h"
//#include <string>


namespace poison_picker
{
	namespace animations
	{
		rinald::rinald(i_led_controller* led_controller, i_dashboard* dashboard) : i_animation(led_controller, dashboard){}

		void rinald::activate(unsigned long milliseconds)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("rinald");
			m_led_controller->set_all_leds(rgb(0, 0, 0));
			m_led_controller->show();
		}
		
		void rinald::update(unsigned long milliseconds)
		{
			m_dashboard->display_set_cursor(0, 1);
			m_dashboard->display_write("  ");
			m_dashboard->display_set_cursor(0, 1);
			m_dashboard->display_write(m_index);


			if (milliseconds > m_previous_milliseconds + m_delay) 
			{
				m_previous_milliseconds = milliseconds;
				
				m_led_controller->set_led(m_index, rgb(0, 0, 0));
				
				m_index++;
				if (m_index >= m_led_controller->get_number_of_leds())
				{
					m_index = 0;
				}

				m_led_controller->set_led(m_index, rgb(255, 255, 255));
				m_led_controller->show();
			}
		}



		void rinald::deactivate(unsigned long milliseconds) {}
	}
}