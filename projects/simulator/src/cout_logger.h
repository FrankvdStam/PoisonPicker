#pragma once
#include "pplib/pplib.h"
#include <iostream>
#include <string>

class cout_logger : public i_logger
{
public:
	cout_logger() : i_logger() {}

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

private:
	void cout_write(std::string str);
	void cout_newline();
};