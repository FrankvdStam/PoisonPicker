#include "cout_logger.h"

void cout_logger::cout_write(std::string str)
{
	std::cout << str;
}

void cout_logger::cout_newline()
{
	std::cout << std::endl;
}






void cout_logger::print(const char* s)
{
	std::string str(s);
	cout_write(str);
}

void cout_logger::print(char c)
{
	std::string str(&c);
	cout_write(str);
}

void cout_logger::print(unsigned char c, int f)
{
	_ASSERT(f == DEC, "Non decimal formats not supported");
	std::string str = std::to_string(c);
	cout_write(str);
}

void cout_logger::print(int i, int f)
{
	_ASSERT(f == DEC, "Non decimal formats not supported");
	std::string str = std::to_string(i);
	cout_write(str);
}

void cout_logger::print(unsigned int i, int f)
{
	_ASSERT(f == DEC, "Non decimal formats not supported");
	std::string str = std::to_string(i);
	cout_write(str);
}

void cout_logger::print(long l, int f)
{
	_ASSERT(f == DEC, "Non decimal formats not supported");
	std::string str = std::to_string(l);
	cout_write(str);
}

void cout_logger::print(unsigned long l, int f)
{
	_ASSERT(f == DEC, "Non decimal formats not supported");
	std::string str = std::to_string(l);
	cout_write(str);
}


void cout_logger::println(const char* s)
{
	print(s);
	cout_newline();
}

void cout_logger::println(char c)
{
	print(c);
	cout_newline();
}

void cout_logger::println(unsigned char c, int f)
{
	print(c, f);
	cout_newline();
}

void cout_logger::println(int i, int f)
{
	print(i, f);
	cout_newline();
}

void cout_logger::println(unsigned int i, int f)
{
	print(i, f);
	cout_newline();
}

void cout_logger::println(long l, int f)
{
	print(l, f);
	cout_newline();
}

void cout_logger::println(unsigned long l, int f)
{
	print(l, f);
	cout_newline();
}

void cout_logger::println(void)
{
	cout_newline();
}