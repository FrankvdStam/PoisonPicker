#include "dashboard.h"

//init
dashboard::dashboard()
{
	m_rotary_encoder = new Encoder(ROTARY_ENCODER_PIN1, ROTARY_ENCODER_PIN2);

	pinMode(BUTTON_PIN_KEY			, INPUT_PULLUP);
	pinMode(BUTTON_PIN_TOGGLE_STATE	, INPUT_PULLUP);
	pinMode(BUTTON_PIN_RANDOMIZE	, INPUT_PULLUP);
	pinMode(BUTTON_PIN_SWITCH		, INPUT_PULLUP);

	//Initialize the lcd
	lcd = new LiquidCrystal(DISPLAY_PIN_RS, DISPLAY_PIN_EN, DISPLAY_PIN_D4, DISPLAY_PIN_D5, DISPLAY_PIN_D6, DISPLAY_PIN_D7);
	lcd->begin(DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

//Update every cycle so that locks and the like on buttons can be reset
void dashboard::update(unsigned long milliseconds)
{
	//buttons are pullup up, default high, low-activated. Flip it around here right away for easy of mind.
	bool button_value = !digitalRead(BUTTON_PIN_KEY);
	m_key = false;
	if (m_can_toggle_key && button_value) 
	{
		m_can_toggle_key = false;
		m_key = button_value;
	}

	if (!button_value)
	{
		m_can_toggle_key = true;
	}
	
	
				   
	//Debounce toggle_state
	button_value = !digitalRead(BUTTON_PIN_TOGGLE_STATE);

	if (button_value != toggle_state_previous)
	{
		toggle_state_debounce_time = milliseconds;

		
	}

	if (milliseconds - toggle_state_debounce_time > BUTTON_DEBOUNCE_DELAY)
	{
		m_toggle_state = button_value;
	}
	
	toggle_state_previous = button_value;

	//The other buttons are direct
	//toggle_state	= !digitalRead(BUTTON_PIN_TOGGLE_STATE);
	m_randomize		= !digitalRead(BUTTON_PIN_RANDOMIZE);

	m_switch = !digitalRead(BUTTON_PIN_SWITCH);


	m_rotary_encoder_change = 0;
	long rotary_encoder_value = m_rotary_encoder->read() / 4;
	if (rotary_encoder_value != m_rotary_encoder_previous)
	{
		m_rotary_encoder_change = rotary_encoder_value - m_rotary_encoder_previous;
		m_rotary_encoder_previous = rotary_encoder_value;
	}


	//i_logger::get().print("key: ");
	//i_logger::get().print(button_pressed_key());
	//i_logger::get().print("\n");
	//
	//i_logger::get().print("toggle state: ");
	//i_logger::get().print(button_pressed_toggle_state());
	//i_logger::get().print("\n");
	//
	//i_logger::get().print("randomize: ");
	//i_logger::get().print(button_pressed_randomize());
	//i_logger::get().print("\n");
	//
	//i_logger::get().print("switch: ");
	//i_logger::get().print(button_pressed_switch());
	//i_logger::get().print("\n");
}

//buttons
bool dashboard::button_pressed_key() { return m_key; }
bool dashboard::button_pressed_toggle_state() { return m_toggle_state; }
bool dashboard::button_pressed_randomize() { return m_randomize; }
bool dashboard::button_pressed_switch() { return m_switch; }

int dashboard::rotary_encoder_change()
{ 
	return m_rotary_encoder_change;
}

//display
void dashboard::display_clear()
{
	lcd->clear();
}
	
void dashboard::display_write(const char* string) 
{
	lcd->write(string);
}

void dashboard::display_write(unsigned char i)
{
	lcd->print(i, DEC);
}

void dashboard::display_write(int i)
{
	lcd->print(i, DEC);
}

void dashboard::display_write(long i)
{
	lcd->print(i, DEC);
}

void dashboard::display_set_cursor(int x, int y) {
	lcd->setCursor(x, y);
}