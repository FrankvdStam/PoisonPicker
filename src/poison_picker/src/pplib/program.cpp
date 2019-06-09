#include "program.h"

/*
enum state {
	disabled,
	enabled,
	randomize
} ;


enum inner_state {
	flow,
	color_wheel,
	brightness
} ;
*/

poison_picker::devices::i_led_controller* s_led_controller;
poison_picker::devices::i_dashboard* s_dashboard;

poison_picker::animations::color_wheel* s_color_wheel;

void init(poison_picker::devices::i_led_controller* led_controller, poison_picker::devices::i_dashboard* dashboard)
{
	//i_led_controller* led = new led_controller();

	s_led_controller = led_controller;
	s_dashboard = dashboard;

	s_color_wheel = new poison_picker::animations::color_wheel(s_led_controller, s_dashboard);
}

void update(unsigned long miliseconds)
{
	s_dashboard->update();


	s_color_wheel->update(miliseconds);
}