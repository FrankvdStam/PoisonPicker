#pragma once
#include "i_animation.h"
#include "../random.h"

#define AMOUNT_OF_COLORS 34

namespace poison_picker 
{
	namespace animations
	{
		class flow : public i_animation
		{
		public:
			flow(i_led_controller* led_controller, i_dashboard* dashboard);

			void activate(unsigned long milliseconds);
			void update(unsigned long milliseconds);
			void deactivate(unsigned long milliseconds);
		private:
			void reflow();

			unsigned char approach(unsigned char source, unsigned char destination, unsigned char increment);
			rgb get_random_rgb();

			unsigned char m_flow_increment = 1;
			long m_flow_interval = 5;
			unsigned long m_previous_milliseconds = 0;

			rgb* m_current_colors;
			rgb* m_random_colors;

			rgb m_colors[AMOUNT_OF_COLORS] = {
				rgb(0  , 0  , 255),	  //Blue,
				rgb(220, 20 , 60 ),	  //Crimson,
				rgb(0  , 255, 255),	  //Cyan,
				rgb(255, 215, 0  ),	  //Gold,
				rgb(0  , 255, 0  ),	  //Lime,
				rgb(0  , 100, 0  ),	  //DarkGreen,
				rgb(0  , 128, 0  ),	  //Green,
				rgb(0  , 255, 0  ),	  //Lime,
				rgb(255, 165, 0  ),	  //Orange,
				rgb(255, 69 , 0  ),	  //OrangeRed,
				rgb(218, 112, 214),	  //Orchid,
				rgb(128, 0  , 128),	  //Purple,
				rgb(255, 0  , 0  ),	  //Red,
				rgb(64 , 224, 208),	  //Turquoise,
				rgb(238, 130, 238),	  //Violet,
				rgb(255, 255, 0  ),	  //Yellow,
				rgb(154, 205, 50 ),	  //YellowGreen,
				rgb(255, 127, 80 ),	  //Coral,
				rgb(139, 0  , 0  ),	  //DarkRed,
				rgb(0  , 206, 209),	  //DarkTurquoise,
				rgb(165, 42 , 42 ),	  //Brown,
				rgb(222, 184, 135),	  //BurlyWood,
				rgb(184, 134, 11 ),	  //DarkGoldenrod,
				rgb(30 , 144, 255),	  //DodgerBlue,
				rgb(178, 34 , 34 ),	  //FireBrick,
				rgb(255, 0  , 255),	  //Fuchsia,
				rgb(218, 165, 32 ),	  //Goldenrod,
				rgb(75 , 0  , 130),	  //Indigo,
				rgb(128, 0  , 0  ),	  //Maroon,
				rgb(0  , 250, 154),	  //MediumSpringGreen,
				rgb(107, 142, 35 ),	  //OliveDrab,
				rgb(139, 69 , 19 ),	  //SaddleBrown,
				rgb(70 , 130, 180),	  //SteelBlue,
				rgb(0  , 128, 128),	  //Teal
			};
		};
	}

}



