#pragma once
#include "pins.h"
#include "src/pplib/include/pplib/pplib.h"
#include "src/FastLED/FastLED.h"
#include "src/FastLED/pixeltypes.h"

#define NUMBER_OF_LEDS					36
#define NUMBER_OF_SEGMENTS				9
#define NUMBER_OF_LEDS_PER_SEGMENTS		4

class led_controller : public poison_picker::devices::i_led_controller {
public:
	led_controller();

	void set_led(unsigned int index, poison_picker::rgb rgb);
	void set_all_leds(poison_picker::rgb rgb);
	void set_segment(unsigned int index, poison_picker::rgb rgb);

	void set_brightness(int brightness);
	void clear();
	void show();

private:
	CRGB leds[NUMBER_OF_LEDS];
};
