// Read keyboard
//Stop reading when $ typed
//Report total number

/*
	Module 3 - Mastery Check - 1
*/

#include <iostream>
int main()
{
	std::cout << "Insert a character, periods count is shown when $ is typed \n\n";

	char input;
	int periods = 0;

	do
	{	
		std::cout << "Insert: ";
		std::cin >> input;
		if(input == '.') periods++;

	} while(input != '$');

	std::cout << periods << " periods typed";

	return 0;
}