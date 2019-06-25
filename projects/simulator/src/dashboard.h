#pragma once
#include "pplib/pplib.h"


class dashboard : public i_dashboard
{
public:

	void update(unsigned long milliseconds) override {}

	bool button_pressed_key() override
	{
		return key;
	}

	bool button_pressed_toggle_state() override
	{
		return toggle_state;
	}

	bool button_pressed_randomize() override
	{
		return randomize;
	}

	int rotary_encoder_change()  override
	{
		return m_rotary_encoder_change;
	}

	//methods to control the display
	void display_clear() override {}
	void display_write(const char* string) override {}
	void display_write(unsigned char i) override {};
	void display_write(int i) override {};
	void display_write(long i) override {};
	void display_set_cursor(int x, int y) override {}
	
	bool key = false;
	bool toggle_state = false;
	bool randomize = false;

	int m_rotary_encoder_change = 0;
};