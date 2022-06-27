#include <iostream>

// Module 5 - Mastery 10 - Print from 0 to 10 with recursion

void printNum(int num);

int main()
{
	printNum(10);
	return 0;
}

void printNum(int num)
{
	if(num > 1) printNum(num - 1);
	std::cout << num << "\n";
}