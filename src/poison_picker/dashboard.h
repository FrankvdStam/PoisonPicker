#include "src/LiquidCrystal/src/LiquidCrystal.h"
#include "src/pplib/pplib.h"

//Arduino headers: you need arduino ide for these

//Need this for analogRead/digitalRead/write
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\Arduino.h"

//Button pins
#define BUTTON_PIN_KEY			6
#define BUTTON_PIN_TOGGLE_STATE 7
#define BUTTON_PIN_RANDOMIZE	8
#define BUTTON_DEBOUNCE_DELAY   50

//Display pins
#define DISPLAY_PIN_RS 12
#define DISPLAY_PIN_EN 11
#define DISPLAY_PIN_D4 5
#define DISPLAY_PIN_D5 4
#define DISPLAY_PIN_D6 3
#define DISPLAY_PIN_D7 2

//Display size
#define DISPLAY_WIDTH 20
#define DISPLAY_HEIGHT 4

//potmeter (14 is mapped to A0 on Arduino uno)
#define POTMETER_PIN 14 
#define POTMETER_SENSITIVITY 10

class dashboard : public poison_picker::devices::i_dashboard
{
public:
	dashboard();

	//Update every cycle so that locks and the like on buttons can be reset
	void update(unsigned long milliseconds);


	//This button is in a 3D-printen case with a spring
	//The button is activated by inserting and turning a key
	//Activates the leds (enables state machine?)
	bool button_pressed_key();

	//This button toggles the global state (color wheel, flow, etc.)
	bool button_pressed_toggle_state();

	//Toggles randomize state, which automatically reverts back to the original state.
	bool button_pressed_randomize();

	//potmeter to turn the color wheel or set the brightness
	int potmeter_value();

	//methods to control the display
	void display_clear();
	void display_write(const char* string);
	void display_set_cursor(int x, int y);

private:
	LiquidCrystal* lcd;
	
	bool key = false;
	bool can_toggle_key = true;

	bool toggle_state = false;
	bool toggle_state_previous = false;
	bool can_toggle_state = true;
	unsigned long toggle_state_debounce_time = 0;

	bool randomize = false;
	bool can_toggle_randomize = true;

	int potmeter = 0;
	int potmeter_previous = 0;
	int potmeter_sensitivity = 10;
};