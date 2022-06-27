// Mastery check 6-4

#include <iostream>
#include <cmath>

void myRoundFunc(double &num);

int main()
{
	double num;

	std::cout << "Insert number to round: \n";
	std::cin >> num;

	myRoundFunc(num);

	std::cout << "Rounded num: " << num;



	return 0;	
}

void myRoundFunc(double &num)
{
	double integer;
	double fractional;

	fractional = modf(num, &integer);

	if(fractional < 0.5) num = integer;
	else num = integer + 1;
}