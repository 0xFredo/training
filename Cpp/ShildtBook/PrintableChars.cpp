#include <iostream>

int main()
{
	unsigned char ch = 32;

	while(ch)
	{
		std::cout << ch << std::endl;
		ch++;
	}

	return 0;
}