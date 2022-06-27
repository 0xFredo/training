// Mastery check Module 6-5
#include <iostream>

int &min_swap(int &num1, int &num2);

int main()
{
	int num1, num2;

	std::cout << "Insert num1: ";
	std::cin >> num1;

	std::cout << "Insert num2: ";
	std::cin >> num2;

	std::cout << "Minimum is: " << min_swap(num1, num2);

}

int &min_swap(int &num1, int &num2)
{
	int tmp = num1;
	num1 = num2;
	num2 = tmp;

	std::cout << "Now num1 = " << num1 << " and num2 = " << num2 << "\n";

	if(num1 < num2) return num1;
	else return num2;
}

