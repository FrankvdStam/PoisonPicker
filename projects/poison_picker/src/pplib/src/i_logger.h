#pragma once

namespace poison_picker
{
	/*
	usage:

	if (i_logger::available())
	{
		i_logger::get().print("toggle_state: ");
		i_logger::get().print(toggle_state);
		i_logger::get().print("\n");
	}
	*/

	#define DEC 10
	#define HEX 16
	#define OCT 8
	#define BIN 2

	class i_logger
	{
	public:
		i_logger();

		static void set(i_logger* instance);
		static i_logger& get();
		static bool available();
		
		virtual void print(const char* c) = 0;
		virtual void print(char c) = 0;
		virtual void print(unsigned char c, int f = DEC) = 0;
		virtual void print(int i, int f = DEC) = 0;
		virtual void print(unsigned int i, int f = DEC) = 0;
		virtual void print(long l, int f = DEC) = 0;
		virtual void print(unsigned long l, int f = DEC) = 0;
		
		virtual void println(const char* c) = 0;
		virtual void println(char c) = 0;
		virtual void println(unsigned char c, int f = DEC) = 0;
		virtual void println(int i, int f = DEC) = 0;
		virtual void println(unsigned int i, int f = DEC) = 0;
		virtual void println(long l, int f = DEC) = 0;
		virtual void println(unsigned long l, int f = DEC) = 0;
		virtual void println(void) = 0;

	private:
		static i_logger* s_instance;
	};	
}
