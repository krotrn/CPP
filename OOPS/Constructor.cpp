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
};

int main()
{
    Bike tvs(25,200);   //  Object Creation //  calling constructor -   by default
    Bike Honda(50,400);
    Bike Sony(100,800);
}

// All Concept Of Constructor
// 1. Constructor is a special member function of a class which is used to initialize the objects of the class.
// 2. Constructor has the same name as the class.
// 3. Constructor does not have a return type.
// 4. Constructor is automatically called when the object is created.
// 5. Constructor is used to initialize the objects of the class.
// 6. Constructor is used to allocate memory to the objects of the class.
// 7. Constructor is used to initialize the data members of the class.
// 8. Constructor is used to perform some operations when the object is created.
// 9. Constructor is used to initialize the objects of the class.

// Types of Constructor
// 1. Default Constructor
// Default Constructor is a constructor which does not take any arguments.
// Default Constructor is automatically called when the object is created.
// Default Constructor is used to initialize the objects of the class.
// Default Constructor is used to allocate memory to the objects of the class.
// Default Constructor is used to initialize the data members of the class.
// Default Constructor is used to perform some operations when the object is created.
// 2. Parameterized Constructor
// Parameterized Constructor is a constructor which takes arguments.
// Parameterized Constructor is used to initialize the objects of the class.
// Parameterized Constructor is used to allocate memory to the objects of the class.
// 3. Copy Constructor
// Copy Constructor is a constructor which initializes an object using another object of the same class.
// Copy Constructor is used to initialize the objects of the class.
// Copy Constructor is used to allocate memory to the objects of the class.
// Copy Constructor is used to initialize the data members of the class.
// Copy Constructor is used to perform some operations when the object is created.



