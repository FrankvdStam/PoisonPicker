#pragma once

namespace poison_picker
{
	namespace devices
	{

		class i_dashboard
		{
		public:
			//Update every cycle so that locks and the like on buttons can be reset
			virtual void update(unsigned long milliseconds) = 0;

			//This button is in a 3D-printen case with a spring
			//The button is activated by inserting and turning a key
			//Activates the leds (enables state machine?)
			virtual bool button_pressed_key() = 0;

			//This button toggles the global state (color wheel, flow, etc.)
			virtual bool button_pressed_toggle_state() = 0;

			//Toggles randomize state, which automatically reverts back to the original state.
			virtual bool button_pressed_randomize() = 0;

			//potmeter to turn the color wheel or set the brightness
			virtual int potmeter_value() = 0;

			//methods to control the display
			virtual void display_clear() = 0;
			virtual void display_write(const char* string) = 0;
			virtual void display_write(unsigned char i) = 0;
			virtual void display_set_cursor(int x, int y) = 0;
		};
	}
}