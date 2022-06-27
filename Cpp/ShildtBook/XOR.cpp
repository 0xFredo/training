/*
	Project 2-2
*/

#include <iostream>

int main()
{
	bool p, q;

	p = true;
	q = true;

	std::cout << p << " XOR " << q << " is " << ( (p || q) && !(p && q) ) << "\n";

	p = false;
	q = true;

	std::cout << p << " XOR " << q << " is " << ( (p || q) && !(p && q) ) << "\n";

	p = true;
	q = false;

	std::cout << p << " XOR " << q << " is " << ( (p || q) && !(p && q) ) << "\n";

	p = false;
	q = false;

	std::cout << p << " XOR " << q << " is " << ( (p || q) && !(p && q) ) << "\n";

	return 0;
}