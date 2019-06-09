class led_controller : public poison_picker::i_led_controller {
public:

	led_controller() : i_led_controller(72, 9, 8) {}

	void set_led(unsigned int index, CRGB& crgb) {

	}

	void set_segment(unsigned int index, CRGB& crgb) {

	}

	void clear() {
		FastLED.clear();
	}
};