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

private:
	bool open = true;

	const int window_width = 800;
	const int window_height = 600;
	GLFWwindow* m_window;

};