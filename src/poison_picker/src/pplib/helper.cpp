#include "helper.h"

namespace poison_picker
{

	long helper::numeric_map(const long x, const long in_min, const long in_max, const long out_min, const long out_max)
	{
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}

}