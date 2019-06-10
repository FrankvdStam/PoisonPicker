#include "debug.h"

namespace poison_picker
{
	i_logger::i_logger() {}

	void i_logger::set(i_logger* instance)
	{
		s_instance = instance;
	}

	i_logger& i_logger::get()
	{
		return *s_instance;
	}

	bool i_logger::available()
	{
		return s_instance != nullptr;
	}

	i_logger* i_logger::s_instance = 0;
}