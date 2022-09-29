#include <iostream>

int main()
{
	double jovianYears, earthYears;

	std::cout << "Insert Jovian Years. \n";
	std::cin >> jovianYears;

	earthYears = jovianYears * 12.0;

	std::cout << jovianYears << " Jovian years are equivalent to " << earthYears << " Earth years";

	return 0;
}