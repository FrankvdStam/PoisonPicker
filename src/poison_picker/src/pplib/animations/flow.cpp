#include "flow.h"
#include "../debug.h"

namespace poison_picker
{
	namespace animations
	{
		flow::flow(i_led_controller* led_controller, i_dashboard* dashboard) 
			: i_animation(led_controller, dashboard) 
		{
			i_logger::get().print("init flow.");
			m_current_colors = new rgb[m_led_controller->get_number_of_segments()];
			m_random_colors  = new rgb[m_led_controller->get_number_of_segments()];
			i_logger::get().print("after init flow.");
		}

		void flow::activate(unsigned long milliseconds)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("flow\n");


			for (unsigned int i = 0; i < m_led_controller->get_number_of_segments(); i++) {
				m_current_colors[i] = rgb(0,0,0);
				m_random_colors[i] = get_random_rgb();
			}
		}

		void flow::update(unsigned long milliseconds) 
		{
			for (int i = 0; i < m_led_controller->get_number_of_segments(); i++) {
				if (m_current_colors[i] == m_random_colors[i]) {
					m_random_colors[i] = get_random_rgb();
				}
				
				//Approach the rgb values
				unsigned char r = approach(m_current_colors[i].r, m_random_colors[i].r, m_flow_increment);
				unsigned char g = approach(m_current_colors[i].g, m_random_colors[i].g, m_flow_increment);
				unsigned char b = approach(m_current_colors[i].b, m_random_colors[i].b, m_flow_increment);

				rgb appoach_color(r, g, b);
				m_current_colors[i] = appoach_color;
				m_led_controller->set_segment(i, appoach_color);					
			}
			m_led_controller->show();
		}

		void flow::deactivate(unsigned long milliseconds)
		{
		}

		unsigned char flow::approach(unsigned char source, unsigned char destination, unsigned char increment)
		{
			if (source != destination)
			{
				if (source > destination)
				{
					return source -= increment;
				}
				else
				{
					return source += increment;
				}
			}
			return source;
		}		

		rgb flow::get_random_rgb() 
		{
			return rgb(random(0, 256), random(0, 256), random(0, 256));
		}
	}
}


//////Create flowing pattern by generating new colors for each led and then approaching them over time
////void flow() {
////	//For every segment..
////	for (int segment = 0; segment < NUM_LED_SEGMENTS; segment++) {
////		//Check the first led of this segment against the randomized color
////		if (leds[segment * LEDS_PER_SEGMENT] == random_colors[segment]) {
////			random_colors[segment] = get_random_color();
////			/*
////				  if(segment == 0){
////					Serial.print("Generated a new color for segment ");
////					Serial.print(segment);
////					Serial.print(": ");
////					PrintColor(randomColors[segment]);
////					Serial.print("\n");
////				  }*/
////		}
////		else
////		{
////
////			CRGB approach_color = approach(leds[segment * LEDS_PER_SEGMENT], random_colors[segment]);
////			/*
////				  if(segment == 0){
////					Serial.print("Approaching, old: ");
////					PrintColor(leds[segment * LEDS_PER_SEGMENT]);
////					Serial.print(", new: ");
////					PrintColor(approach);
////					Serial.print("\n");
////				  }
////				  */
////			set_segment(segment, approach_color);
////		}
////	}
////}
////
////CRGB colors[] = {
////		CRGB::Blue,
////		CRGB::Crimson,
////		CRGB::Cyan,
////		CRGB::Gold,
////		CRGB::Lime,
////		CRGB::DarkGreen,
////		CRGB::Green,
////		CRGB::Lime,
////		CRGB::Orange,
////		CRGB::OrangeRed,
////		CRGB::Orchid,
////		CRGB::Purple,
////		CRGB::Red,
////		CRGB::Turquoise,
////		CRGB::Violet,
////		CRGB::Yellow,
////		CRGB::YellowGreen,
////		CRGB::Coral,
////		CRGB::DarkRed,
////		CRGB::DarkTurquoise,
////		CRGB::Brown,
////		CRGB::BurlyWood,
////		CRGB::DarkGoldenrod,
////		CRGB::DodgerBlue,
////		CRGB::FireBrick,
////		CRGB::Fuchsia,
////		CRGB::Goldenrod,
////		CRGB::Indigo,
////		CRGB::Maroon,
////		CRGB::MediumSpringGreen,
////		CRGB::OliveDrab,
////		CRGB::SaddleBrown,
////		CRGB::SteelBlue,
////		CRGB::Teal
////}; //34
////
////CRGB get_random_color() {
////	return colors[random(NUM_COLORS)];
////}
////