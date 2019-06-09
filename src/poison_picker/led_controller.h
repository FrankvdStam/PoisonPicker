#pragma once
#include "src/pplib/pplib.h"
#include "src/FastLED/FastLED.h"
#include "src/FastLED/pixeltypes.h"

#define NUMBER_OF_LEDS					72
#define NUMBER_OF_SEGMENTS				9
#define NUMBER_OF_LEDS_PER_SEGMENTS		8
#define LED_PIN							10

class led_controller : public poison_picker::devices::i_led_controller {
public:
	led_controller();

	void set_led(unsigned int index, poison_picker::rgb rgb);
	void set_all_leds(poison_picker::rgb rgb);
	void set_segment(unsigned int index, poison_picker::rgb rgb);

	void set_brightness(unsigned char brightness);
	void clear();
	void show();

private:
	CRGB leds[NUMBER_OF_LEDS];
};