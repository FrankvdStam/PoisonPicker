#include <iostream>
#include <pplib.h>

struct CRGB {
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

class led_controller : public poison_picker::i_led_controller {
public:

	led_controller() : i_led_controller(72, 9, 8){}

	void set_led(unsigned int index, CRGB crgb)  {

	}

	void set_segment(unsigned int index, CRGB crgb) {

	}

	void clear() {

	}

	void show() {

	}
};


int main(int argc, char** argv)
{
	std::cout << "Fucking halfwitt" << std::endl;
	led_controller led_controller;
	led_controller.clear();
}