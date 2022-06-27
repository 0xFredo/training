#include <iostream>
#include <cmath>

class RightTriangle
{
	double base;
	double height;

public:
	RightTriangle(double baseInit, double heightInit)
	{
		base = baseInit;
		height = heightInit;
	}

	double hypot()
	{
		return sqrt( (base*base) + (height*height) );
	}


	double area()
	{
		return (base*height) / 2.0;
	}

};

int main()
{
	RightTriangle triangle(5.0, 10.0);

	std::cout << "Hypotenuse: " << triangle.hypot() << "\n";
	std::cout << "Area: " << triangle.area() << "\n";

	return 0;
}