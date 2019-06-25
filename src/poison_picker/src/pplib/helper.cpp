#include "helper.h"
#include "i_logger.h"

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
}