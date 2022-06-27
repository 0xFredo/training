#include <iostream>
#include <cstring>

class TwoDShape
{
    double width;
    double height;
    char name[20];

public:

    TwoDShape()
    {
        width = height = 0.0;
        strcpy(name, "unknown");

    }

    TwoDShape(double w, double h, char *n)
    {
        width = w;
        height = h;
        strcpy(name, n);
    }

    TwoDShape(double x, char *n)
    {
        width = height = x;
        strcpy(name, n);
    }

    void showDim()
    {
        std::cout << "Width and height are " << width << " and " << height << "\n";
    }

    double getWidth() { return width; }
    double getHeight() { return height; }
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }
    char *getName() { return name; }

    virtual double getArea() = 0;

};

class Circle : public TwoDShape
{   
    const double PI_GRECO = 3.1416;

public:

    Circle() { }
    Circle(double r) : TwoDShape(r, "Circle") { }

    double getArea() 
    { 
        return getWidth() * getWidth() * PI_GRECO;
    }
};


int main()
{
    Circle circle(3.0);
    std::cout << "Circle area is: " << circle.getArea();

    return 0;
}