#include <iostream>
#include <pplib.h>

struct rgb {
	inline rgb(int r, int g, int b) : r(r), g(g), b(b) {}

	int r;
	int g;
	int b;
};


class base {
public:
	virtual void test() = 0;
};

class derived : public base{
	void test() {
		std::cout << "Derived" << std::endl;
	}
};

int main(int argc, char** argv)
{
	std::cout << "Fucking halfwitt" << std::endl;
	

	rgb a(1, 1, 1);
	std::cout << a.r;// << std::end;

	base* thing = new derived();
	thing->test();

}