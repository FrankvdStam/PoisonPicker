#include <iostream>

#include "pplib/pplib.h"
#include "led_controller.h"
#include "dashboard.h"
#include "graphics/renderer.h"
#include <chrono>

//To be implemented by a client

auto start_time = std::chrono::high_resolution_clock::now();

auto finish = std::chrono::high_resolution_clock::now();

class cout_logger : public i_logger
{
public:
	cout_logger() : i_logger(){}

	void print(const char* str) override
	{ 
		std::cout << str << std::endl;
	}

	void print(int i) override
	{ 
		std::cout << i << std::endl;
	}	

	void print(unsigned long i) override
	{
		std::cout << i << std::endl;
	}

	void print(unsigned char i) override
	{
		std::cout << i << std::endl;
	}
};

long random(long min, long max)
{
	return 0;
}


int main(int argc, char** argv)
{
	i_logger::set(new cout_logger());
	if (i_logger::available()) {
		i_logger& logger = i_logger::get();
		logger.print("logger initialized");
	}

	renderer* r = new renderer();

	i_led_controller* m_led_controller = new led_controller(r);
	i_dashboard* m_dashboard = new dashboard();

	i_animation** animations = new i_animation * [3];
	animations[0] = new flow(m_led_controller, m_dashboard);
	animations[1] = new color_wheel(m_led_controller, m_dashboard);
	animations[2] = new brightness(m_led_controller, m_dashboard);
	   	 
	animator* m_animator = new animator(m_led_controller, m_dashboard, animations, 3);

	m_led_controller->set_all_leds(rgb(255, 0, 0));
	m_led_controller->set_segment(4, rgb(0, 255, 0));
	m_led_controller->show();
	while(true)
	{

		auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
		unsigned long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
		m_animator->update(milliseconds);
		r->poll_events();
		r->draw();
	}	
}