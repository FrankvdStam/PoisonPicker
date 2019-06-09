#pragma once


#include "C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\HardwareSerial.h"
HardwareSerial* get_serial();


/*
#include <iostream>
using std::cout;
using std::endl;
class HardwareSerial {
public:
	void print(const char* str) { cout << str << endl; }
	void println(const char* str) { cout << str << endl; }

	void print(int i) { cout << i << endl; }
	void println(char c) { cout << c << endl; }
};

HardwareSerial* get_serial() {
	return new HardwareSerial();
}
*/
