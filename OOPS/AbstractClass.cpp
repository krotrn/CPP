#include <iostream>
using namespace std;

class Vehicle
{
public:
    int tyresize;
    int enginsize;
    virtual void calculateMilage() = 0;
    virtual void refuel() = 0;
};

class Bike : public Vehicle
{
public:
    int handleSize;
    void calculateMilage()
    {
        cout << "Bike Milage" << endl;
    }
    void refuel() {
        cout << "Bike REFUEL" << endl;
    }
};

int main()
{
    Bike b;
    b.calculateMilage();
    b.refuel();
}