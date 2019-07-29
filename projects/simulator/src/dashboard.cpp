#include "dashboard.h"

void dashboard::update(unsigned long milliseconds)
{
	m_key = m_renderer->m_key;
	m_toggle_state = m_renderer->m_toggle_state;
	m_randomize = m_renderer->m_randomize;
	m_switch = m_renderer->m_switch;

	m_rotary_encoder_change = 0;
	if (m_previous_rotary_encoder_value != m_renderer->m_rotary_encoder)
	{
		m_rotary_encoder_change = m_renderer->m_rotary_encoder - m_previous_rotary_encoder_value;
		m_previous_rotary_encoder_value = m_renderer->m_rotary_encoder;
	}
}

bool dashboard::button_pressed_key() 
{
	return m_key;
}

bool dashboard::button_pressed_toggle_state()
{
	return m_toggle_state;
}

bool dashboard::button_pressed_randomize()
{
	return m_randomize;
}

bool dashboard::button_pressed_switch()
{
	return m_switch;
}

int dashboard::rotary_encoder_change() 
{
	return m_rotary_encoder_change;
}