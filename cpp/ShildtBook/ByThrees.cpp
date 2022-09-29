#include <iostream>

int seriesNum = 0;

int byThrees();
void reset();

int main()
{

	for(int i = 0; i < 10; i++)
		std::cout << byThrees() << " ";

	std::cout << "\n";
	reset();

	for(int i = 0; i < 10; i++)
		std::cout << byThrees() << " ";

	return 0;
}

int byThrees()
{
	int toIncrese = seriesNum;
	seriesNum += 3;

	return toIncrese;
}

void reset()
{
	seriesNum = 0;
}