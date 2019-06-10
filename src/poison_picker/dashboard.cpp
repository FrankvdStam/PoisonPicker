#include "dashboard.h"

//init
dashboard::dashboard()
{
	pinMode(BUTTON_PIN_KEY			, INPUT_PULLUP);
	pinMode(BUTTON_PIN_TOGGLE_STATE	, INPUT_PULLUP);
	pinMode(BUTTON_PIN_RANDOMIZE	, INPUT_PULLUP);
	
	//Initialize the lcd
	lcd = new LiquidCrystal(DISPLAY_PIN_RS, DISPLAY_PIN_EN, DISPLAY_PIN_D4, DISPLAY_PIN_D5, DISPLAY_PIN_D6, DISPLAY_PIN_D7);
	lcd->begin(DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

//Update every cycle so that locks and the like on buttons can be reset
void dashboard::update(unsigned long milliseconds)
{
	//buttons are pullup up, default high, low-activated. Flip it around here right away for easy of mind.
	bool button_value = !digitalRead(BUTTON_PIN_KEY);

	//The key is a toggle
	if (button_value && can_toggle_key) {
		can_toggle_key = false;
		key = !key;
	}

	if (!button_value) {
		can_toggle_key = true;
	}
			   
	//Debounce toggle_state
	button_value = !digitalRead(BUTTON_PIN_TOGGLE_STATE);

	if (button_value != toggle_state_previous)
	{
		toggle_state_debounce_time = milliseconds;

		
	}

	if (milliseconds - toggle_state_debounce_time > BUTTON_DEBOUNCE_DELAY)
	{
		toggle_state = button_value;
	}
	
	toggle_state_previous = button_value;

	//The other buttons are direct
	//toggle_state	= !digitalRead(BUTTON_PIN_TOGGLE_STATE);
	randomize		= !digitalRead(BUTTON_PIN_RANDOMIZE);

	//debounce potmeter to reduce flickering
	int potmeter_value = analogRead(POTMETER_PIN);
	if (potmeter_value + POTMETER_SENSITIVITY < potmeter_previous || potmeter_value - POTMETER_SENSITIVITY > potmeter_previous)
	{
		potmeter = potmeter_value;
		potmeter_previous = potmeter;
	}
}

//buttons
bool dashboard::button_pressed_key() { return key; }
bool dashboard::button_pressed_toggle_state() { return toggle_state; }
bool dashboard::button_pressed_randomize() { return randomize; }
int dashboard::potmeter_value() { return potmeter; }

//display
void dashboard::display_clear()
{
	lcd->clear();
}
	
void dashboard::display_write(const char* string) 
{
	if (i_logger::available()) {
		i_logger::get().print(string);
	}
	lcd->write(string);
}

void dashboard::display_set_cursor(int x, int y) {
	lcd->setCursor(x, y);
}