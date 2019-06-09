struct CRGB;

namespace poison_picker {
	class i_led_controller {
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

		virtual void set_led(unsigned int index, CRGB& crgb) = 0;
		virtual void set_segment(unsigned int index, CRGB& crgb) = 0;

		virtual void clear() = 0;
			   
	private:
		unsigned int number_of_leds;
		unsigned int number_of_segments;
		unsigned int number_of_leds_per_segment;
	};
}




int add(int a, int b) {
	return a + b;
}