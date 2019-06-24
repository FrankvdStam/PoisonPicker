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

	class i_logger
	{
	public:
		i_logger();

		static void set(i_logger* instance);
		static i_logger& get();
		static bool available();

		virtual void print(const char* str) = 0;
		virtual void print(int i) = 0;
		virtual void print(unsigned long i) = 0;
		virtual void print(unsigned char i) = 0;
	private:
		static i_logger* s_instance;
	};	
}
