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
		
	ImGui::Begin("main window", &open, ImVec2(800,600));
	ImGui::Button("Hello world!");
	
	/*
	 Drawing the leds by index:
	 1-8	9-16	17-24
	41-48	33-40	25-32
	49-56	56-64	65-72
	 */
	const int row_size = 24;
	const int col_size = 8;

	int index;
	for(int i = 0; i < m_leds.size(); i++)
	{		
		int index = serpentine_map(i, 24);
		std::cout << i << ": " << index << std::endl;

		ImGui::ColorButton("", ImVec4(m_leds[index].r , m_leds[index].g, m_leds[index].b, 255));

		//Draw a bit of margin between groups of 8
		if((i+1) % 24 != 0 && (i+1) % 8 == 0)
		{
			ImGui::SameLine();
		}
		//If not a group of 8 but also not a group of 24 (no newline) , draw the leds close to each other.
		else if((i+1) % 24 != 0)
		{
			ImGui::SameLine(0, 0);
		}
	}

	ImGui::ShowDemoWindow(&open);

	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(m_window);
}

void renderer::poll_events()
{
	glfwPollEvents();
}

void renderer::update_leds(std::vector<rgb> leds)
{
	m_leds = leds;
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