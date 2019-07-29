#pragma once
#include <vector>
#include <string>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"

class renderer
{
public:
	renderer();

	void draw();
	void poll_events();
	bool window_should_close();

	void update_leds(std::vector<rgb> leds);

	//Button values
	bool m_key = false;
	bool m_toggle_state = false;
	bool m_randomize = false;
	bool m_switch = false;
	int m_rotary_encoder = 0;

	std::string m_display_text;
private:
	static int serpentine_map(int i, int length);

	std::vector<ImVec4> m_led_colors;

	bool open = true;

	const int window_width = 800;
	const int window_height = 600;
	GLFWwindow* m_window;
};