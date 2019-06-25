#include "pins.h"
#include "src/Encoder/Encoder.h"
#include "src/LiquidCrystal/src/LiquidCrystal.h"
#include "src/pplib/include/pplib/pplib.h"

//Arduino headers: you need arduino ide for these

//Need this for analogRead/digitalRead/write
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\Arduino.h"

#define BUTTON_DEBOUNCE_DELAY   50

//Display size
#define DISPLAY_WIDTH 20
#define DISPLAY_HEIGHT 4

#define POTMETER_SENSITIVITY 10

class dashboard : public poison_picker::devices::i_dashboard
{
public:
	dashboard();

	void update(unsigned long milliseconds);

	bool button_pressed_key();
	bool button_pressed_toggle_state();
	bool button_pressed_randomize();

	int rotary_encoder_change();

	void display_clear();
	void display_write(const char* string);
	void display_write(unsigned char i);
	void display_write(int i);
	void display_write(long i);
	void display_set_cursor(int x, int y);

private:
	LiquidCrystal* lcd;
	Encoder* m_rotary_encoder;
	
	bool key = false;
	bool can_toggle_key = true;

	bool toggle_state = false;
	bool toggle_state_previous = false;
	bool can_toggle_state = true;
	unsigned long toggle_state_debounce_time = 0;

	bool randomize = false;
	bool can_toggle_randomize = true;

	long m_rotary_encoder_previous = 0;
	long m_rotary_encoder_change = 0;
};
