#include<iostream>
using namespace std;
// Function Overriding
// Function Overriding is a feature of C++ where a function in a base class is redefined in a derived class.
// In Function Overriding, the function in the derived class has the same name, return type, and parameters as the function in the base class.
// The function in the derived class overrides the function in the base class.
// The function in the derived class is called when the function is called using the object of the derived class.
// The function in the base class is called when the function is called using the object of the base class.
// The function in the base class is called when the function is called using the object of the derived class.
// The function in the derived class is called when the function is called using the object of the base class.

class Vehicle
{
public:
    int tyres;
    int enginsize;
    virtual void show() // virtual keyword is used to make the function virtual.
    // runtime binding is done in case of virtual functions.
    {
        cout << "Vehicle" << endl;
    }
};

class Bike : public Vehicle
{
public:
    int handlesize;
    void show()
    // compile time binding is done in case of non-virtual functions.
    {
        cout << "Bike" << endl;
    }
};

// int main()
// {
//     // compile time : Vehicle::show() is called using the object of the base class.
//     // run time : Bike::show() is called using the object of the derived class.

//     Vehicle a;
//     Bike b;
//     a.show();
//     b.show();   // Bike::show() overrides Vehicle::show() in this case because Bike is derived from Vehicle and Bike::show() is defined in Bike.

//     // using Scope Resolution Operator
//     b.Vehicle::show();    // Vehicle::show() is called using the object of the derived class.
    
//     // using Base Class Object
//     Vehicle *ptr = new Bike; // Vehicle pointer pointing to the object of the derived class.
//     // base class pointer can point to the object of the derived class.
    
//     ptr->show();    // Vehicle::show() is called using the object of the base class.
//     ptr = new Vehicle;
//     ptr->show();    // Vehicle::show() is called using the object of the base class.

//     return 0;
// }

class C : public Bike
{
public:
    void show()
    {
        cout << "C" << endl;
    }
};

// int main()
// {
//     Bike *b;
//     b = new C;
//     b->show();  // C::show() called because vehicle has virtual show() then Bike::show() also become virtual and C::show() overrides Bike::show() ("doubt").
// }

int main()
{
    Vehicle a;
    Bike b;
    cout << sizeof(a) << endl
         << sizeof(b) << endl;
}