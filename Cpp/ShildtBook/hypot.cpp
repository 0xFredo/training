#include <iostream>
#include <cmath>

double hypot(double side1, double side2);

int main()
{
	std::cout << "Hypotenuse of a 5 by 6 right triangle: " << hypot(5.0, 6.0);
}

double hypot(double side1, double side2)
{
	return sqrt( (side1*side1) + (side2*side2) );
}