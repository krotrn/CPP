#include<iostream>
using namespace std;

class Bike {
public:
    int tyresize;
    int enginsize;
    // //  making default constructor
    // Bike ()
    // {
    //     cout << "Calling Constructor\n";
    // }

    //  making parameterized constructor
    //  for value initialization
    Bike (int tyresize, int enginsize)
    {
        this->tyresize = tyresize;
        this->enginsize = enginsize;
        cout << "Calling Constructor\n";
    }
    ~Bike(){
        cout << "Calling Deestructor\n";
    }
};

int main()
{
    // Bike tvs;   //  Object Creation //  calling constructor -   by default
    // Bike Honda;
    // Bike Sony;

    bool f = true;
    if(f){
        Bike bmw(200, 2000);
    }
    Bike tvs(25,200);   //  Object Creation //  calling constructor -   by parameterized
    Bike Honda(50,400);
    Bike Sony(100,800);
}

// Destructor is a special member function of a class that is executed automatically when an object of it goes out of scope or is explicitly destroyed.
// It is used to release resources allocated by the object during its lifetime.

// In the given code, the destructor is already defined for the class Bike. It is defined using the tilde (~) symbol followed by the class name.
// The destructor is called automatically when the object of the class goes out of scope or is explicitly destroyed.

// If you want to add some additional code in the destructor, you can do so by modifying the existing destructor definition.

// For example, you can add a print statement to display a message when the destructor is called:

