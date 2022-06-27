#include <iostream>
#include <cstdlib>

int main()
{
	double val, average;
	average = 0.0;

	for(int i = 0; i < 5; i++)
	{
		std::cout << "Insert value: ";	
		std::cin >> val;
		average += std::abs(val);
	}
	average /= 5;
	std::cout << "The average of absolute values is " << average;

}