//Module 7 Mastery 5 
#include <iostream>

int counter();

int main()
{

	int numCall;
	for(int i = 0; i < 5; i++)
	{
		numCall = counter();
	}

	std::cout << "Counter called " << numCall << " times\n";


	return 0;
}

int counter()
{
	static int counter = 0;
	counter++;

	return counter;
}