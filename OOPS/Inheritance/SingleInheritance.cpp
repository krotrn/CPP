#include <iostream>
using namespace std;
class Vehicle // Base class
{
public:
    int tyresize;
    int enginsize;
    int light;
    string CompanyName;
    void showCompanyName()
    {
        cout << "Company Name: " << CompanyName << endl;
    }
};
class Bike : public Vehicle // Bike is a Vehicle
{
public:
    int BikeTyreSize;
};

class A
{
private:
    int a_private;

protected:
    int a_protected;

public:
    int a_public;
};

class B : public A
 // If we use public inheritance then all the public and protected members of the base class will become public and protected members of the derived class respectively

// class B : protected A // If we use protected inheritance then all the public and protected members of the base class will become protected members of the derived class

// class B : private A // If we use private inheritance then all the public and protected members of the base class will become private members of the derived class

{
    // a_private is not accessible cannot be accessed and inherited
    // a_protected is protected cannot be accecible but can be inherited
    // a_public is public can be accessed and inherited
    public:
        int b_public;
    protected:
        int b_protected;
    private:
        int b_private;
    
};

int main() // Main method
{
    // Bike b;
    // b.CompanyName = "Honda";   // Accessing the base class member
    // b.showCompanyName();    // Accessing the base class member function
    // return 0;
}
// private -> protected -> public // Access Specifiers in Inheritance


// in public inheritance, the public members of the base class become public members of the derived class and protected members of the base class become protected members of the derived class

// in protected inheritance, the public members of the base class become protected members of the derived class and protected members of the base class become protected members of the derived class

// in private inheritance, the public members of the base class become private members of the derived class and protected members of the base class become private members of the derived class



// we cannot downgrade any member of base class in derived class. if

// In class B : protected A, we cannot access a_protected in main function but we can access it in derived class B, and protected member of A will become protected member of B and public member of A will become protected member of B, 

// similarly in class B : private A, we cannot access a_protected in main function but we can access it in derived class B, and protected member of A will become private member of B and public member of A will become private member of B and we cannot access them in main function 
// And for class B: public A, we can access all the members of A in main function and in derived class B and they will be public and protected members of B respectively.