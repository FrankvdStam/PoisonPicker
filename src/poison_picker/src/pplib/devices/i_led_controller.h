#pragma once
#include "../rgb.h"


namespace poison_picker {
	namespace devices {

		class i_led_controller 
		{
		public:
			i_led_controller(
				unsigned int number_of_leds,
				unsigned int number_of_segments,
				unsigned int number_of_leds_per_segment
			) :
				m_number_of_leds(number_of_leds),
				m_number_of_segments(number_of_segments),
				m_number_of_leds_per_segment(number_of_leds_per_segment)
			{
			}

			virtual void set_led(unsigned int index, rgb rgb) = 0;
			virtual void set_all_leds(rgb rgb) = 0;
			virtual void set_segment(unsigned int index, rgb rgb) = 0;
			virtual void set_brightness(unsigned char brightness) = 0;

			virtual void clear() = 0;
			virtual void show() = 0;

		protected:
			unsigned int m_number_of_leds;
			unsigned int m_number_of_segments;
			unsigned int m_number_of_leds_per_segment;
		};
	}
}