/*
	Project 4-2
	Reverse a string in place
*/
#include <iostream>
#include <cstring>

int main()
{
	char str[] = "this is a test";
	char *start, *end;
	int stringLength;

	std::cout << "Original: " << str << "\n";

	stringLength = strlen(str);
	start = str;
	end = &str[stringLength-1];

	while(start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
	}

	std::cout << "Reversed: " << str;

	return 0;
}