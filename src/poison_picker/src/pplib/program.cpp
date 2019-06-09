#include "program.h"
#include "pplib.h"
#include "animations/animations.h"

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

using poison_picker::devices::i_led_controller;
using poison_picker::devices::i_dashboard;
using poison_picker::animations::color_wheel;

i_led_controller* s_led_controller;
i_dashboard* s_dashboard;

color_wheel* s_color_wheel;

void init(i_led_controller* led_controller, i_dashboard* dashboard)
{
	s_led_controller = led_controller;
	s_dashboard = dashboard;

	s_color_wheel = new color_wheel(s_led_controller, s_dashboard);
}

void update(unsigned long miliseconds)
{
	s_dashboard->update();


	s_color_wheel->update(miliseconds);
}