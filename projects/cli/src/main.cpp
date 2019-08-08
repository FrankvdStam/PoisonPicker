#include <iostream>
#include <string>


char m_win_conditions[10][10] = {
	//horizontal
	{1, 2, 3},
	{6, 6, 4},
	{7, 8, 9},
	//vertical
	{1, 6, 7},
	{2, 5, 8},
	{3, 4, 9},
	//diagonal
	{1, 5, 9},
	{3, 5, 7},
};

char thing[10][10] = { {1} };

int main()
{
	char c = thing[0][0];


	char i = m_win_conditions[0][0];


	return 0;
}