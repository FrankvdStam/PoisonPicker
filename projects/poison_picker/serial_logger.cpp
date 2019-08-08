#include "serial_logger.h"

void serial_logger::print(const char* s)
{
	Serial.print(s);
}

void serial_logger::print(char c)
{
	Serial.print(c);
}

void serial_logger::print(unsigned char c, int f)
{
	Serial.print(c, f);
}

void serial_logger::print(int i, int f)
{
	Serial.print(i, f);
}

void serial_logger::print(unsigned int i, int f)
{
	Serial.print(i, f);
}

void serial_logger::print(long l, int f)
{
	Serial.print(l, f);
}

void serial_logger::print(unsigned long l, int f)
{
	Serial.print(l, f);
}



void serial_logger::println(const char* s)
{
	Serial.println(s);
}

void serial_logger::println(char c)
{
	Serial.println(c);
}

void serial_logger::println(unsigned char c, int f)
{
	Serial.println(c, f);
}

void serial_logger::println(int i, int f)
{
	Serial.println(i, f);
}

void serial_logger::println(unsigned int i, int f)
{
	Serial.println(i, f);
}

void serial_logger::println(long l, int f)
{
	Serial.println(l, f);
}

void serial_logger::println(unsigned long l, int f)
{
	Serial.println(l, f);
}

void serial_logger::println(void)
{
	Serial.println();
}