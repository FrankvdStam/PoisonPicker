#include <iostream>
#include <string>



class rgb {
public:
	rgb() : r(0), g(0), b(0) {}
	rgb(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b){}
	rgb(int r, int g, int b) : r(r), g(g), b(b) {}

	unsigned char r;
	unsigned char g;
	unsigned char b;

	friend std::ostream& operator<<(std::ostream& os, const rgb& rgb)
	{
		os << "(" << std::to_string(rgb.r) << "," << std::to_string(rgb.g) << "," << std::to_string(rgb.b) << ")";
		return os;
	}
};

//RGB can't be negative. We need a proper vector.
class vector3i {
public:
	vector3i() : x(0), y(0), z(0) {}
	vector3i(int r, int g, int b) : x(r), y(g), z(b) {}
	vector3i(rgb rgb) : x(rgb.r), y(rgb.g), z(rgb.b) {}


	int x;
	int y;
	int z;

	friend std::ostream& operator<<(std::ostream& os, const vector3i& vector3i)
	{
		os << "(" << vector3i.x << "," << vector3i.y << "," << vector3i.z << ")";
		return os;
	}
};


vector3i calculate_approach_vector(vector3i a, vector3i b, int steps)
{
	return vector3i((b.x - a.x)/steps, (b.y - a.y)/steps, (b.z - a.z)/steps);
}



int main()
{
	rgb a(10, 6, 12);
	rgb b(20, 1, 26);

	
	//std::cout << vec;

	for (int i = 5; i > 0; i--)
	{
		vector3i veca(a);
		vector3i vecb(b);

		vector3i ap = calculate_approach_vector(veca, vecb, i);
		a.r += ap.x;
		a.g += ap.y;
		a.b += ap.z;

		std::cout << a << std::endl;
	}
	

	return 0;
}