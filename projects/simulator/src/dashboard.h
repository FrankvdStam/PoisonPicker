#pragma once
#include "pplib/pplib.h"


class dashboard : public i_dashboard
{
public:
	dashboard(renderer* r) : m_renderer(r) 
	{

	}

	void update(unsigned long milliseconds) override 
	{
		m_key			= m_renderer->m_key;
		m_toggle_state	= m_renderer->m_toggle_state;
		m_randomize		= m_renderer->m_randomize;
		m_switch		= m_renderer->m_switch;

		m_rotary_encoder_change = 0;
		if (m_previous_rotary_encoder_value != m_renderer->m_rotary_encoder)
		{
			m_rotary_encoder_change = m_renderer->m_rotary_encoder - m_previous_rotary_encoder_value;
			m_previous_rotary_encoder_value = m_renderer->m_rotary_encoder;
		}
	}

	bool button_pressed_key() override
	{
		return m_key;
	}

	bool button_pressed_toggle_state() override
	{
		return m_toggle_state;
	}

	bool button_pressed_randomize() override
	{
		return m_randomize;
	}

	bool button_pressed_switch() override
	{
		return m_switch;
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
	

	bool m_key			= false;
	bool m_toggle_state = false;
	bool m_randomize	= false;
	bool m_switch		= false;

	renderer* m_renderer;
	int m_previous_rotary_encoder_value = 0;
	int m_rotary_encoder_change = 0;
};