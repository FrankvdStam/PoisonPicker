#pragma once
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

	void update_leds(std::vector<rgb> leds);

private:
	static int serpentine_map(int i, int length);

	std::vector<rgb> m_leds;

	bool open = true;

	const int window_width = 800;
	const int window_height = 600;
	GLFWwindow* m_window;

};