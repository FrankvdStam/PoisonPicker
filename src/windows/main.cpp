#include <iostream>
#include <pplib.h>
#include "led_controller.h"
#include "dashboard.h"

int main(int argc, char** argv)
{
	std::cout << "Fucking halfwitt" << std::endl;
	
	i_led_controller* m_led_controller = new led_controller();
	dashboard* m_dashboard = new dashboard();

	i_animation** animations = new i_animation * [1];
	animations[0] = new color_wheel(m_led_controller, m_dashboard);
	animations[1] = new brightness(m_led_controller, m_dashboard);

	animator* m_animator = new animator(m_led_controller, m_dashboard, animations, 2);
	
	while (true) {
		m_animator->update(0);
		m_dashboard->toggle_state = true;
		m_animator->update(0);
		m_dashboard->toggle_state = false;
	}


	int i = 0;
	int* p = &i;
	int in = *p;
}