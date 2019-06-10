#pragma once

typedef unsigned char uint8_t;

namespace poison_picker
{

	struct rgb {
		inline rgb(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
		inline rgb() : r(0), g(0), b(0) {}

		

		unsigned char r;
		unsigned char g;
		unsigned char b;
	};

	inline bool operator==(const rgb& left, const rgb& right)
	{
		return left.r == right.r && left.g == right.g && left.b == right.b;
	}

}