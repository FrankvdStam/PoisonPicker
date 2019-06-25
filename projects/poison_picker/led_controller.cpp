#include "led_controller.h"

led_controller::led_controller() : i_led_controller(NUMBER_OF_LEDS, NUMBER_OF_SEGMENTS, NUMBER_OF_LEDS_PER_SEGMENTS)
{
	FastLED.addLeds<WS2812, LED_PIN, EOrder::GRB>(leds, NUMBER_OF_LEDS);
	FastLED.setBrightness(100);
	FastLED.clear();
}

void led_controller::set_led(unsigned int index, poison_picker::rgb rgb)
{
	leds[index] = CRGB(rgb.r, rgb.g, rgb.b);
}

void led_controller::set_all_leds(poison_picker::rgb rgb)
{
	CRGB color = CRGB(rgb.r, rgb.g, rgb.b);
	for (int i = 0; i < NUMBER_OF_LEDS; i++) {
		leds[i] = color;
	}
}

void led_controller::set_segment(unsigned int index, poison_picker::rgb rgb)
{
	CRGB color = CRGB(rgb.r, rgb.g, rgb.b);
	for (int i = index * NUMBER_OF_LEDS_PER_SEGMENTS; i < (index + 1) * NUMBER_OF_LEDS_PER_SEGMENTS; i++)
	{
		leds[i] = color;
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