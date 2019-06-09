#pragma once

typedef unsigned char uint8_t;

namespace poison_picker
{

	struct rgb {
		inline rgb(int r, int g, int b) : r(r), g(g), b(b) {}

		int r;
		int g;
		int b;
	};

}