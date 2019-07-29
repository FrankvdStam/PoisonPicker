#include "../simulator_pch.h"
#include "renderer.h"

renderer::renderer()
{
	glfwInit();
	m_window = glfwCreateWindow(window_width, window_height, "simulator", nullptr, nullptr);
	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL2_Init();

	//ImGuiIO& io = ImGui::GetIO(); (void)io;
	//ImGui::PushFont(io.Fonts->Fonts[0]);
}


void renderer::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
		
	ImGui::Begin(" ", &open, ImVec2(800,600), ImGuiWindowFlags_NoTitleBar & ImGuiWindowFlags_NoMove & ImGuiWindowFlags_NoResize);
	
	/*
	 Drawing the leds by index:
	 1-8	9-16	17-24
	41-48	33-40	25-32
	49-56	56-64	65-72
	 */
	const int row_size = 12;
	const int col_size = 4;

	for(unsigned int i = 0; i < m_led_colors.size(); i++)
	{		
		int index = serpentine_map(i, 12);
		ImGui::ColorButton("", m_led_colors[index]);
		
		//Draw a bit of margin between groups of 4
		if((i+1) % 12 != 0 && (i+1) % 4 == 0)
		{
			ImGui::SameLine();
		}
		//If not a group of 4 but also not a group of 12 (no newline) , draw the leds close to each other.
		else if((i+1) % 12 != 0)
		{
			ImGui::SameLine(0, 0);
		}
	}


	m_randomize		= ImGui::Button("Randomize");
	ImGui::SameLine();
	m_toggle_state	= ImGui::Button("Toggle state");
	ImGui::SameLine();

	// Arrow buttons with Repeater
	float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
	ImGui::PushButtonRepeat(true);
	if (ImGui::ArrowButton("##left", ImGuiDir_Left)) { m_rotary_encoder--; }
	ImGui::SameLine(0.0f, spacing);
	if (ImGui::ArrowButton("##right", ImGuiDir_Right)) { m_rotary_encoder++; }
	ImGui::PopButtonRepeat();
	ImGui::SameLine();

	ImGui::SameLine();
	m_switch		= ImGui::Button("Switch");
	ImGui::SameLine();
	m_key			= ImGui::Button("Key");

	ImGui::Text(m_display_text.c_str());
	
	//ImGui::ShowDemoWindow(&open);

	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(m_window);
}

void renderer::poll_events()
{
	glfwPollEvents();
}

bool renderer::window_should_close() 
{
	return glfwWindowShouldClose(m_window);
}

void renderer::update_leds(std::vector<rgb> leds)
{
	m_led_colors.clear();
	for(unsigned int i = 0; i < leds.size(); i++)
	{
		m_led_colors.emplace_back(
			static_cast<float>(leds[i].r)/255, 
			static_cast<float>(leds[i].g)/255, 
			static_cast<float>(leds[i].b)/255, 
			1.0f
		);
	}

}


/*
Get a serpentine map. ex:

 0	1  2  3  4  5  6  7 
15 14 13 12 11 10  9  8
16 17 18 19 20 21 22 23
 */

int renderer::serpentine_map(int i, int length)
{
	const int row = (i / length) + 1;

	if (row % 2 != 0)
	{
		return i;
	}
	else
	{
		const int max = (row * length) - 1;
		const int min = ((row - 1) * length);
		return (min + max) - i;
	}
}