#pragma once
#include "i_logger.h"
#include "rgb.h"
#include "random.h"

namespace poison_picker
{
	//Yeah.. lets find a better name for this.
	class helper {
	public:			   
		static long numeric_map(const long x, const long in_min, const long in_max, const long out_min, const long out_max);
		static int amount_of_digits(int number);
		static long approach_looparound(const long current_value, const long increment, const long min, const long max);
		static void log_rgb(rgb rgb, bool newline);
		static bool rgb_array_contains(rgb* rgb_array, unsigned int size, rgb rgb);
	};
}
