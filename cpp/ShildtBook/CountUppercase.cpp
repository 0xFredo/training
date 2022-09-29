#include <iostream>
#include <cctype>

int main()
{

	char input[80];
	int uppercaseCounter = 0;

	std::cout << "Insert string: " << "\n";
	std::cin >> input;

	for(int i = 0; input[i]; i++)
	{
		if(isupper(input[i]))
			uppercaseCounter++;
	}

	std::cout << uppercaseCounter << " uppercase letters.";

	return 0;
}