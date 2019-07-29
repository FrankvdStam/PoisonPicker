#pragma once
#include <iostream>
#include <string>

#include "pplib/pplib.h"
#include "graphics/renderer.h"

class dashboard : public i_dashboard
{
public:
	dashboard(renderer* r) : m_renderer(r) 
	{
		//clear display to fill it with ' '
		display_clear();
	}

	void update(unsigned long milliseconds);

	//Button methods
	bool button_pressed_key()				override;
	bool button_pressed_toggle_state()		override;
	bool button_pressed_randomize()			override;
	bool button_pressed_switch()			override;
	int rotary_encoder_change()				override;

	//methods to control the display
	void display_clear()					override;
	void display_write(const char* string)	override;
	void display_write(unsigned char i)		override;
	void display_write(int i)				override;
	void display_write(long i)				override;
	void display_set_cursor(int x, int y)	override;
	
	void display_write_std_string(std::string string);
	void display_flush();


	bool m_key			= false;
	bool m_toggle_state = false;
	bool m_randomize	= false;
	bool m_switch		= false;

	renderer* m_renderer;
	int m_previous_rotary_encoder_value = 0;
	int m_rotary_encoder_change = 0;

	int m_cursor_x = 0;
	int m_cursor_y = 0;

	const static size_t m_display_text_width = 20;
	const static size_t m_display_text_height = 4;

	char m_display_text[m_display_text_width][m_display_text_height];
};