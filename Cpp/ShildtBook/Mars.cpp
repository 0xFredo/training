#include <iostream>

int main()
{
	double distance, lightspeed, delay, delay_in_min;

	distance = 34000000.0; //miles
	lightspeed = 186000.0; //miles per second for a radio signal

	delay = distance / lightspeed; // seconds to reach Mars

	std::cout << "Time delay when talking to Mars: " << delay << " seconds. \n";

	delay_in_min = delay / 60;

	std::cout << "This is minutes: " << delay_in_min;

	return 0;
}