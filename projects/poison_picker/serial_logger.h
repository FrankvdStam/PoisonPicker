#pragma once
#include "src/pplib/include/pplib/pplib.h"

class serial_logger : public i_logger
{
public:
	serial_logger() : i_logger() {}

	void print(const char* str)
	{
		Serial.print(str);
	}

	void print(int i)
	{
		Serial.print(i);
	}

	void print(unsigned long i)
	{
		Serial.print(i);
	}

	void print(unsigned char i)
	{
		Serial.print(i);
	}
};