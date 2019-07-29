#include "helper.h"

namespace poison_picker
{
	long helper::numeric_map(const long x, const long in_min, const long in_max, const long out_min, const long out_max)
	{
		return (x - in_min) * (out_max - out_min + 1) / (in_max - in_min + 1) + out_min;
	}
	
	int helper::amount_of_digits(int number)
	{
		if (number == 0)
		{
			return 1;
		}

		int size = 0;
		while (number > 0)
		{
			number /= 10;
			size++;
		}
		return size;
	}

	long helper::approach_looparound(const long current_value, const long increment, const long min, const long max)
	{
		if (current_value + increment < min)
		{
			return max + (increment + current_value);
		}
		else if (current_value + increment > max)
		{
			return min + ((current_value + increment) - max);
		}
		else
		{
			return current_value + increment;
		}
	}

	void helper::log_rgb(rgb rgb, bool newline)
	{
		if (i_logger::available())
		{
			i_logger& logger = i_logger::get();
			logger.print("(");
			logger.print(rgb.r);
			logger.print(","); 
			logger.print(rgb.g);
			logger.print(","); 
			logger.print(rgb.b);
			logger.print(")");
			if (newline) {
				logger.print("\n");
			}
		}
	}

	bool helper::rgb_array_contains(rgb* rgb_array, unsigned int size, rgb rgb)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (rgb_array[i] == rgb)
			{
				return true;
			}
		}
		return false;
	}
}