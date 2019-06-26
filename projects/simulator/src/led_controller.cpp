#include "simulator_pch.h"
#include "led_controller.h"


led_controller::led_controller(renderer* renderer) : i_led_controller(72, 9, 8)
{
	m_renderer = renderer;

	for (unsigned int i = 0; i < m_amount_of_leds; i++)
	{
		m_leds.emplace_back(rgb(0, 0, 0));
	}
}

void led_controller::set_led(unsigned int index, rgb rgb)
{
	m_leds[index] = rgb;
}

void led_controller::set_all_leds(rgb rgb)
{
	for (unsigned int i = 0; i < m_amount_of_leds; i++)
	{
		m_leds[i] = rgb;
	}
}

void led_controller::set_segment(unsigned int index, rgb rgb)
{
	int transform = index * m_segment_size;
	for(unsigned int i = 0; i < m_segment_size; i++)
	{
		m_leds[transform + i] = rgb;
	}
}

void led_controller::set_brightness(int brightness)
{
	m_brightness = brightness;
}

void led_controller::clear()
{
	for (unsigned int i = 0; i < m_amount_of_leds; i++)
	{
		m_leds[i] = rgb(0,0,0);
	}
}

void led_controller::show()
{
	//Copy by val, not by ref. The renderer needs to have it's own copy that doesn't update
	//until led_controller show is called.
	std::vector<rgb> leds(m_leds);
	m_renderer->update_leds(leds);
}