/*
	Module 3 - Mastery Check - 11
*/

//if lower upper and viceversa

#include <iostream>
int main()
{

	char input;
	int changeCounter = 0;
	
	do
	{
		std::cout << "Insert char to convert: ";
		std::cin >> input;

		if(input >= 'a' && input <= 'z')
		{
			std::cout << "Result: " << (input -= 32) << "\n";
			changeCounter++;
		} 
		else if(input >= 'A' && input <= 'Z')
		{
			std::cout << "Result: " << (input += 32) << "\n";
			changeCounter++;
		}
		else
		{
			std::cout << "Enter a valid char! \n";
		}

	} while(input != '.');

	std::cout << changeCounter << " case change occurs.";

}