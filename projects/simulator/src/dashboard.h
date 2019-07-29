#pragma once
#include "pplib/pplib.h"
#include "graphics/renderer.h"

class dashboard : public i_dashboard
{
public:
	dashboard(renderer* r) : m_renderer(r) {}

	void update(unsigned long milliseconds);

	//Button methods
	bool button_pressed_key() override;
	bool button_pressed_toggle_state() override;
	bool button_pressed_randomize() override;
	bool button_pressed_switch() override;
	int rotary_encoder_change() override;

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