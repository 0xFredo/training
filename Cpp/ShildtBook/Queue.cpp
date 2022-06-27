//Module 8-2
//Seems that the element 0 of the array is not used
#include <iostream>

const int maxQsize = 100;

class Queue 
{
	char q[maxQsize];
	int size;
	int putloc, getloc;

public:

	Queue(int len)
	{
		if(size > maxQsize) len = maxQsize;
		else if(len <= 0) len = 1;

		size = len;
		putloc = getloc = 0;
	}

	void put(char ch)
	{
		if(putloc == size)
		{
			std::cout << " -- Queue is full.\n";
			return;
		}

		putloc++;
		std::cout << "Putloc post increment " << putloc;  
		q[putloc] = ch;
	}

	char get()
	{
		if(getloc == putloc)
		{
			std::cout << " -- Queue is empty.\n";
			return 0;
		}

		getloc++;
		return q[getloc];
	}
};

int main()
{
	Queue bigQ(100);
	Queue smallQ(4);

	//Store the alphabet
	for(int i = 0; i < 26; i++)
		bigQ.put('A' + i);

	//Retrive content
	std::cout << "Contents of bigQ: ";
	for(int i = 0; i < 26; i++)
	{
		char ch = bigQ.get();
		if(ch != 0) std::cout << ch;
	}

	std::cout << "\n\n";

	//Store errors
	for(int i = 0; i < 5; i++)
	{
		std::cout << "Attempting to store " << (char) ('Z' - i);
		smallQ.put('Z' - i);

		std::cout << "\n";
	}

	std::cout << "\n";

	//Show errors
	std::cout << "Contents of smallQ: ";
	for(int i = 0; i < 5; i++)
	{
		char ch = smallQ.get();
		if(ch != 0) std::cout << ch;
	}

	std::cout << "\n";

	return 0;
}