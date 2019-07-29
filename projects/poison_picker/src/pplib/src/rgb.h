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

	struct vector3i {
	public:
		inline vector3i() : x(0), y(0), z(0) {}
		inline vector3i(int r, int g, int b) : x(r), y(g), z(b) {}
		inline vector3i(rgb rgb) : x(rgb.r), y(rgb.g), z(rgb.b) {}

		int x;
		int y;
		int z;

		//friend std::ostream& operator<<(std::ostream& os, const vector3i& vector3i)
		//{
		//	os << "(" << vector3i.x << "," << vector3i.y << "," << vector3i.z << ")";
		//	return os;
		//}
	};
}