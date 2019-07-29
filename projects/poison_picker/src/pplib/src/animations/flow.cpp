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
			m_current_steps	 = new int[m_led_controller->get_number_of_segments()];
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
				m_random_colors[i] = colors::get_random_color();
				m_current_steps[i] = random(0, 20);//Give the leds a random offset compared to each other
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
			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++) {
				if (m_current_steps[i] == 0)
				{
					m_current_steps[i] = steps;
					rgb random_rgb = colors::get_random_color();
					while (helper::rgb_array_contains(m_random_colors, m_led_controller->get_number_of_segments(), random_rgb))
					{
						random_rgb = colors::get_random_color();
					}
					m_random_colors[i] = random_rgb;
				}

				vector3i curr(m_current_colors[i]);
				vector3i rand(m_random_colors[i]);

				vector3i approach_vector = calculate_approach_vector(curr, rand, m_current_steps[i]);
				m_current_steps[i]--;

				m_current_colors[i].r += approach_vector.x;
				m_current_colors[i].g += approach_vector.y;
				m_current_colors[i].b += approach_vector.z;
				m_led_controller->set_segment(i, m_current_colors[i]);
			}
			m_led_controller->show();
		}

		void flow::deactivate(unsigned long milliseconds)
		{
		}

		vector3i flow::calculate_approach_vector(vector3i a, vector3i b, int steps)
		{
			return vector3i((b.x - a.x) / steps, (b.y - a.y) / steps, (b.z - a.z) / steps);
		}
	}
}