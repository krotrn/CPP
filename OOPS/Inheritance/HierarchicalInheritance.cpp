#include <iostream>
using namespace std;
// Hierarchical Inheritance
// Hierarchical Inheritance is a feature of C++ where a class can inherit from more than one class.
// In Hierarchical Inheritance, a class can inherit from more than one class.
// The derived class inherits all the features of the base classes.
// The derived class can access the features of all the base classes.
// The derived class can access the features of the base classes using the scope resolution operator (::).
// The derived class can access the features of the base classes using the object of the derived class.
// The derived class can access the features of the base classes using the object of the base class.
// eg: Class A is a base class for Class B and Class C. So, Class B and Class C are derived classes for Class A.

class A
{
public:
    int a_public;
    void showA()
    {
        cout << "A: " << a_public << endl;
    }
    A()
    {
        a_public = 10;
        cout << "A constructor" << endl;
    }
protected:
    int a_protected;
private:    
    int a_private;
    
};

class B : public A // a_protected is protected a_private is not accessible and a_public is protected
{   
public:
    int b_public;
    void showB()
    {
        cout << "B: " << b_public << endl;
    }
    B()
    {
        cout << "B constructor" << endl;
    }
};

class C : public A // a_protected is protected a_private is not accessible and a_public is protected
{
public:
    int c_public;
    void showC()
    {
        cout << "C: " << c_public << endl;
    }
    C()
    {
        cout << "C constructor" << endl;
    }
};

int main()
{
    B b;
    C c;
    return 0;
}   // main method
// In the above code, class B and class C are derived from class A. So, class B and class C are derived classes for class A.
// C are derived from class A. So, class B and class C are derived classes for class A.