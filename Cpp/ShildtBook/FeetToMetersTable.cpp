/*
	Project 1-2

	Conversion table of feet to meters
*/
#include <iostream>

int main() 
{
	double feet, meters;
	int counter;
	counter = 0;

	for(feet = 1.0; feet <= 100.0; feet++)
	{
		meters = feet / 3.28;
		std::cout << feet << " feet is " << meters << " meters. \n";

		counter++;

		if(counter == 25)
		{
			std::cout << "\n";
			counter = 0;
		}
	} 

	return 0;
}