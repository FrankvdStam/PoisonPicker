#pragma once
#include "rgb.h"

namespace poison_picker
{
	class colors
	{
	public:
		static const rgb* m_colors;
		static const unsigned int s_amount_of_colors = 34;
		static const rgb get_random_color();
		static const rgb get_random_rgb();
	};
	
}
