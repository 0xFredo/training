#include <iostream>

int myStrLen(char *str);

int main()
{

	std::cout << "Length of 'Test String': " << myStrLen("Test String");
	return 0;
}

int myStrLen(char *str)
{

	int counter = 0;
	while(str[counter])
	{
		counter++;
	}

	return counter;
}

