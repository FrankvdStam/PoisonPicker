#include "flow.h"

namespace poison_picker
{
	namespace animations
	{
		flow::flow(i_led_controller* led_controller, i_dashboard* dashboard) 
			: i_animation(led_controller, dashboard) 
		{			
			m_current_colors = new rgb[m_led_controller->get_number_of_segments()];
			m_random_colors  = new rgb[m_led_controller->get_number_of_segments()];
		}

		void flow::activate(unsigned long milliseconds)
		{
			m_previous_milliseconds = milliseconds;
			m_dashboard->display_clear();
			m_dashboard->display_write("flow");
			m_dashboard->display_set_cursor(0, 1);
			m_dashboard->display_write("interval: ");
			m_dashboard->display_write(m_flow_interval);

			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++) {
				m_current_colors[i] = rgb(0,0,0);
				m_random_colors[i] = get_random_rgb();
			}
		}

		void flow::update(unsigned long milliseconds) 
		{
			//Set the interval
			long rotary_encoder_change = m_dashboard->rotary_encoder_change();
			if (rotary_encoder_change != 0)
			{
				m_flow_interval += rotary_encoder_change;

				if (m_flow_interval < 0) 
				{
					m_flow_interval = 0;
				}

				m_dashboard->display_set_cursor(10, 1);
				m_dashboard->display_write("       ");
				m_dashboard->display_set_cursor(10, 1);
				m_dashboard->display_write(m_flow_interval);
			}

			if (m_previous_milliseconds + m_flow_interval < milliseconds) 
			{
				m_previous_milliseconds = milliseconds;
				reflow();
			}
		}

		void flow::reflow()
		{
			//approach the colors
			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++) {
				if (m_current_colors[i] == m_random_colors[i]) {
					m_random_colors[i] = get_random_rgb();
				}

				//Approach the rgb values
				unsigned char r = approach(m_current_colors[i].r, m_random_colors[i].r, m_flow_increment);
				unsigned char g = approach(m_current_colors[i].g, m_random_colors[i].g, m_flow_increment);
				unsigned char b = approach(m_current_colors[i].b, m_random_colors[i].b, m_flow_increment);

				rgb appoach_color(r, g, b);
				m_current_colors[i] = appoach_color;
				m_led_controller->set_segment(i, appoach_color);
			}
			m_led_controller->show();
		}

		void flow::deactivate(unsigned long milliseconds)
		{
		}

		unsigned char flow::approach(unsigned char source, unsigned char destination, unsigned char increment)
		{
			if (source != destination)
			{
				if (source > destination)
				{
					return source -= increment;
				}
				else
				{
					return source += increment;
				}
			}
			return source;
		}		

		rgb flow::get_random_rgb() 
		{
			return m_colors[random(0, AMOUNT_OF_COLORS)];
		}
	}
}