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




void dashboard::display_clear() 
{
	for (unsigned int y = 0; y < m_display_text_height; y++)
	{
		for (unsigned int x = 0; x < m_display_text_width; x++)
		{
			m_display_text[x][y] = ' ';
		}
	}	
	display_set_cursor(0, 0);

	display_flush();
}

void dashboard::display_write(const char* string)
{
	std::string str(string);
	display_write_std_string(str);

	display_flush();
}

void dashboard::display_write(unsigned char i)
{
	std::string s = std::to_string(i);
	display_write_std_string(s);

	display_flush();
}

void dashboard::display_write(int i)
{
	std::string s = std::to_string(i);
	display_write_std_string(s);

	display_flush();
}

void dashboard::display_write(long i)
{
	std::string s = std::to_string(i);
	display_write_std_string(s);

	display_flush();
}

void dashboard::display_set_cursor(int x, int y)
{
	m_cursor_x = x;
	m_cursor_y = y;
}

void dashboard::display_write_std_string(std::string string)
{
	for (char& c : string)
	{
		//handle cursor overflow by reflowing it to next line or back to top
		if (m_cursor_x == m_display_text_width)
		{
			m_cursor_x = 0;
			m_cursor_y++;
		}

		if (m_cursor_y == m_display_text_height)
		{
			m_cursor_y = 0;
		}

		m_display_text[m_cursor_x][m_cursor_y] = c;
		m_cursor_x++;
	}
}

void dashboard::display_flush()
{
	std::string text;
	for (unsigned int y = 0; y < m_display_text_height; y++)
	{
		for (unsigned int x = 0; x < m_display_text_width; x++)
		{
			//std::cout << m_display_text[x][y];
			text += m_display_text[x][y];
		}
		//std::cout << std::endl;
		text += '\n';
	}

	m_renderer->m_display_text = text;
}