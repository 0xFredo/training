#include <iostream>

int main()
{
	double earthPounds, moonPounds;
	int lineCounter = 0;

	for(earthPounds = 1.0; earthPounds <= 100.0; earthPounds++)
	{
		moonPounds = earthPounds * 0.17;
		std::cout << earthPounds << " pounds on Earth are " << moonPounds << " on the Moon. \n";

		lineCounter++;
		if(lineCounter == 25)
		{
			std::cout << "\n";
			lineCounter = 0;
		}
	}

	return 0;
}