#include <iostream>
#include <cctype>

int main()
{

	char firstString[80];
	char secondString[80];

	std::cout << "Enter first string: \n";
	std::cin >> firstString;

	std::cout << "Enter second string: \n";
	std::cin >> secondString;

	char *pointer1 = firstString;
	char *pointer2 = secondString;

	while(*pointer1 && *pointer2)
	{
		if(tolower(*pointer1) == tolower(*pointer2))
		{
			pointer1++;
			pointer2++;
		}
		else break;
	}

	if(!*pointer1 && !*pointer2)
		std::cout << "String are the same. \n";
	else
		std::cout << "String differs. \n";

	return 0;
}