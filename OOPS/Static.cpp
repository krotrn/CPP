#include<iostream>
using namespace std;
class Bike {
public:
    static int noOfBike;
    int tyresize;
    int enginsize;
    Bike (int tyresize, int enginsize = 200)
    {
        this->tyresize = tyresize;
        this->enginsize = enginsize;
    }
    ~Bike(){
        cout << "Calling Deestructor\n";
    }
    static void incnOfBikes()
    {
        noOfBike++;
    }
};


// void print()
// {
//     static int b = 10;
//     cout << b << endl;
//     b++;
// }

// int main()
// {
//     print();
//     print();
//     print();
// }

int Bike::noOfBike = 10;

int maain()
{
    Bike royal(100, 200);
    royal.incnOfBikes();
    cout << royal.noOfBike << endl;
}

// Static member functions are the functions that belong to the class rather than the object of a class.
// Static member functions can be called even if no objects of the class exist and can access only static data members, static member functions, and other static functions.
// Static member functions are declared using the static keyword.
// Static member functions do not have a this pointer.
// Static member functions can be accessed using the class name and the scope resolution operator ::.
// Static member functions are used to perform operations that do not require any object of the class.
// Static member functions are used to access static data members and static member functions of the class.
// Static member functions are used to perform operations that are common to all objects of the class.
