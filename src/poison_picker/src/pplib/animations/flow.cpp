#include "flow.h"

namespace poison_picker
{
	namespace animations
	{
		flow::flow(i_led_controller* led_controller, i_dashboard* dashboard) 
			: i_animation(led_controller, dashboard) {}

		void flow::activate(unsigned long miliseconds)
		{
			m_dashboard->display_clear();
			m_dashboard->display_write("flow\n");
		}

		void flow::update(unsigned long miliseconds) 
		{
			/*
			for (int segment = 0; segment < NUM_LED_SEGMENTS; segment++) {
				//Check the first led of this segment against the randomized color
				if (leds[segment * LEDS_PER_SEGMENT] == random_colors[segment]) {
					random_colors[segment] = get_random_color();
				}
				else
				{
					CRGB approach_color = approach(leds[segment * LEDS_PER_SEGMENT], random_colors[segment]);
					set_segment(segment, approach_color);
				}
			}*/
		}

		void flow::deactivate(unsigned long miliseconds)
		{
		}
	}
}

////
////
////CRGB approach(CRGB source, CRGB destination) {
////	int r = source.r;
////	int g = source.g;
////	int b = source.b;
////
////	if (source.r != destination.r)
////	{
////		if (source.r > destination.r)
////		{
////			r -= FLOW_INCREMENT;
////		}
////		else {
////			r += FLOW_INCREMENT;
////		}
////	}
////
////	if (source.g != destination.g)
////	{
////		if (source.g > destination.g) {
////			g -= FLOW_INCREMENT;
////		}
////		else {
////			g += FLOW_INCREMENT;
////		}
////	}
////
////	if (source.b != destination.b)
////	{
////		if (source.b > destination.b) {
////			b -= FLOW_INCREMENT;
////		}
////		else {
////			b += FLOW_INCREMENT;
////		}
////	}
////
////	return CRGB(r, g, b);
////}
////
////
////
////
////
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