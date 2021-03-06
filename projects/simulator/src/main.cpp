#include <iostream>
#include <stdlib.h> 
#include <chrono>
#include <time.h>
#include <string>

#include "pplib/pplib.h"
#include "led_controller.h"
#include "dashboard.h"
#include "graphics/renderer.h"
#include "cout_logger.h"

auto start_time = std::chrono::high_resolution_clock::now();
auto finish = std::chrono::high_resolution_clock::now();

long random(long min, long max)
{
	return rand() % max + min;
}


int main(int argc, char** argv)
{
	srand(time(NULL));

	i_logger::set(new cout_logger());
	if (i_logger::available()) {
		i_logger& logger = i_logger::get();
		logger.print("logger initialized");
	}

	renderer* r = new renderer();

	i_led_controller* m_led_controller = new led_controller(r);
	i_dashboard* m_dashboard = new dashboard(r);

	i_animation* randomize_animation = new randomize(m_led_controller, m_dashboard);

	i_animation** animations = new i_animation*[6];
	animations[0] = new cylon(m_led_controller, m_dashboard);
	animations[1] = new tictactoe(m_led_controller, m_dashboard);
	animations[2] = new color_wheel(m_led_controller, m_dashboard);
	animations[3] = new flow(m_led_controller, m_dashboard);
	animations[4] = new brightness(m_led_controller, m_dashboard);
	animations[5] = new rinald(m_led_controller, m_dashboard);
	poison_picker::poison_picker* m_poison_picker = new poison_picker::poison_picker(m_led_controller, m_dashboard, randomize_animation, animations, 6);

	while(!r->window_should_close())
	{
		auto elapsed = std::chrono::high_resolution_clock::now() - start_time;
		unsigned long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
		m_poison_picker->update(milliseconds);
		r->poll_events();
		r->draw();
	}	
}