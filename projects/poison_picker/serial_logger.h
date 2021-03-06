#pragma once
#include "src/pplib/include/pplib/pplib.h"
//TODO: figure out how to get rid of this include, it's needed for all serial calls in the cpp file.
#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\Arduino.h"

class serial_logger : public i_logger
{
public:
	serial_logger() : i_logger() {}

	void print(const char* s) override;
	void print(char c) override;
	void print(unsigned char c, int f = DEC) override;
	void print(int i, int f = DEC) override;
	void print(unsigned int i, int f = DEC) override;
	void print(long l, int f = DEC) override;
	void print(unsigned long l, int f = DEC) override;

	void println(const char* s) override;
	void println(char c) override;
	void println(unsigned char c, int f = DEC) override;
	void println(int i, int f = DEC) override;
	void println(unsigned int i, int f = DEC) override;
	void println(long l, int f = DEC) override;
	void println(unsigned long l, int f = DEC) override;
	void println(void) override;
};