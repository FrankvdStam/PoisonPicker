#include <iostream>


const char* int_to_char_ptr(const int i)
{
	int bytes = sizeof(int) / sizeof(char);
	int temp = i;
	for(int i = 0; i < sizeof(int)/sizeof(char); i++)
	{
	}




	int size = sizeof(int);

	return "";
}


int main()
{
	int i = 123;	
	std::cout << int_to_char_ptr(i) << std::endl;
	
	return 0;
}