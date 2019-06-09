#pragma once

//fwd declaration, arduino ide doesn't let us include fastled.
//That means it's up to implementors to implement this struct (for each project)
struct CRGB;

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
				number_of_leds(number_of_leds),
				number_of_segments(number_of_segments),
				number_of_leds_per_segment(number_of_leds_per_segment)
			{
			}

			virtual void set_led(unsigned int index, CRGB crgb) = 0;
			virtual void set_segment(unsigned int index, CRGB crgb) = 0;
			virtual void set_brightness(int brightness) = 0;

			virtual void clear() = 0;
			virtual void show() = 0;

		protected:
			unsigned int number_of_leds;
			unsigned int number_of_segments;
			unsigned int number_of_leds_per_segment;
		};
	}
}