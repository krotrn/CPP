#include<iostream>
using namespace std;
class Vehicle       // Base class
{
public:
    int tyresize;
    int enginsize;
    int light;
    string CompanyName;
};
class Bike : public Vehicle     // Bike is a Vehicle
{
    public:
    int BikeTyreSize;
};