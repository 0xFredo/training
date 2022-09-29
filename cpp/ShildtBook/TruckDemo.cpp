#include <iostream>

class Veichle
{
    int passengers;
    int fuelCap;
    int milePerGallon;

public:
    Veichle(int p, int f, int m)
    {
        passengers = p;
        fuelCap = f;
        milePerGallon = m;
    }

    int range() { return milePerGallon * fuelCap; }

    int get_passengers() { return passengers; }
    int get_fuleCap() { return fuelCap; }
    int get_milePerGallon() { return milePerGallon; }
};

class Truck : public Veichle
{
    int cargoCap; //pounds capacity of cargo;

public:
    Truck(int p, int f, int m, int c) : Veichle(p, f, m)
    {
        cargoCap = c;
    }

    int get_cargoCap() { return cargoCap; }
};


int main()
{
    Truck semiTruck(2, 200, 7, 44000);
    Truck pickUp(3, 28, 15, 2000);
    int dist = 252;

    std::cout << "semiTruck truck can carry: " << semiTruck.get_cargoCap() << " pounds.\n";
    std::cout << "It has a range of " << semiTruck.range() << " miles.\n";
    std::cout << "To go " << dist << " miles semiTruck truck needs " << dist / semiTruck.get_milePerGallon() << " gallons of fuel.\n";

    std::cout << "PickUp can carry: " << pickUp.get_cargoCap() << " pounds.\n";
    std::cout << "It has a range of " << pickUp.range() << " miles.\n";
    std::cout << "To go " << dist << " miles pickUp needs " << dist / pickUp.get_milePerGallon() << " gallons of fuel.\n";
 
    return 0;
}