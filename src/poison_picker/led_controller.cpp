#include "led_controller.h"

led_controller::led_controller() : i_led_controller(NUMBER_OF_LEDS, NUMBER_OF_SEGMENTS, NUMBER_OF_LEDS_PER_SEGMENTS)
{
	FastLED.addLeds<WS2812, 6, EOrder::GRB>(leds, NUMBER_OF_LEDS);
	FastLED.setBrightness(255);
}

void led_controller::set_led(unsigned int index, CRGB crgb)
{
	leds[index] = crgb;
}

void led_controller::set_segment(unsigned int index, CRGB crgb)
{
	for (int i = index * NUMBER_OF_LEDS_PER_SEGMENTS; i < (index + 1) * NUMBER_OF_LEDS_PER_SEGMENTS; i++)
	{
		leds[i] = crgb;
	}
}

void led_controller::set_brightness(int brightness)
{
	FastLED.setBrightness(brightness);
}

void led_controller::clear()
{
	FastLED.clear();
}

void led_controller::show()
{
	FastLED.show();
}