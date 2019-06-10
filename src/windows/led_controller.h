#pragma once
#include "pplib.h"

class led_controller : public i_led_controller
{
public:
	led_controller() : i_led_controller(0,0,0){}

	void set_led(unsigned int index, rgb rgb) {}
	void set_all_leds(rgb rgb) {}
	void set_segment(unsigned int index, rgb rgb) {}
	void set_brightness(unsigned char brightness) {}

	void clear() {}
	void show() {}
};

