#include <iostream>

const int ascii_zero = 48;

static unsigned char* int_to_string_buffer = new unsigned char[4];
char* malloc_int_to_char_ptr(int x)
{
	int size = 0;

	while (x > 0)
	{
		int_to_string_buffer[size] = x % 10;
		x /= 10;
		size++;
	}

	char* c = new char[size+1];
	c[size] = '\0';//add null terminator at the end

	for (int i = size-1; i > -1; i--)
	{
		c[i] = (char)ascii_zero + int_to_string_buffer[i];
	}
	
	return c;
}



int main(int argc, char** argv)
{
	char* c = malloc_int_to_char_ptr(123);
	//char* c = malloc_int_to_char_ptr(123);
	std::cout << c << std::endl;
}