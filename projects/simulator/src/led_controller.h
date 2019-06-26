#pragma once
#include <vector>
#include "pplib/pplib.h"
#include "graphics/renderer.h"

class led_controller : public i_led_controller
{
public:
	led_controller(renderer* renderer);

	void set_led(unsigned int index, rgb rgb) override;
	void set_all_leds(rgb rgb);
	void set_segment(unsigned int index, rgb rgb) override;
	void set_brightness(int brightness)override;

	void clear() override;
	void show() override;

private:
	const unsigned int m_amount_of_leds = 72;
	const unsigned int m_segment_size = 8;
	const unsigned int m_amount_of_segments = 9;
	int m_brightness;
	std::vector<rgb> m_leds;
	renderer* m_renderer;

};

