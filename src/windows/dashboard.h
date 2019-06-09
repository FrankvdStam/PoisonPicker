#pragma once
#include "pplib.h"


class dashboard : public i_dashboard
{
public:

	//Update every cycle so that locks and the like on buttons can be reset
	void update() {}

	//This button is in a 3D-printen case with a spring
	//The button is activated by inserting and turning a key
	//Activates the leds (enables state machine?)
	bool button_pressed_key() { return key; }

	//This button toggles the global state (color wheel, flow, etc.)
	bool button_pressed_toggle_state() { return toggle_state; }

	//Toggles randomize state, which automatically reverts back to the original state.
	bool button_pressed_randomize() { return randomize; }

	//potmeter to turn the color wheel or set the brightness
	int potmeter_value() 
	{
		return potmeter;
	}

	//methods to control the display
	void display_clear() {}
	void display_write(const char* string) {}
	void display_set_cursor(int x, int y) {}


	bool key = false;
	bool toggle_state = false;
	bool randomize = false;

	int potmeter = 0;
};