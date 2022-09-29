/*
	Project 1-1

	Feet to Meters conversion
*/

#include <iostream>

int main()
{
	double feet;
	double meters;

	std::cout << "Enter the length in feet: ";
	std::cin >> feet;

	meters = feet / 3.28;

	std::cout << feet << " feet is " << meters << " meters.\n";
	std::cout << "In reverse " << feet << " meters is " << feet * 3.28 << " feet.";
  
	return 0;
} 