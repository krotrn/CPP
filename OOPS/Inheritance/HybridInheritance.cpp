#include<iostream>
using namespace std;
// Hybrid Inheritance
// Hybrid Inheritance is a feature of C++ where a class can inherit from more than one class and can also inherit from a derived class.
// In Hybrid Inheritance, a class can inherit from more than one class and can also inherit from a derived class.
// The derived class inherits all the features of the base classes.
// The derived class can access the features of all the base classes.
// The derived class can access the features of the base classes using the scope resolution operator (::).
// The derived class can access the features of the base classes using the object of the derived class.

// eg: Class A is a base class for Class B and Class C. Class D is derived from Class B and Class C. So, Class D is a derived class for Class B and Class
// C and Class B and Class C are derived classes for Class A. So, Class D is a derived class for Class A.
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
        cout << "A constructor" << endl;
    }
    protected:
        int a_protected;
    private:
        int a_private;
};

class B : public A // a_protected is protected a_private is not accessible and a_public is public
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

class C : public A // a_protected is protected a_private is not accessible and a_public is public
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

class D : public B, public C // a_protected is protected a_private is not accessible and a_public is public
                            // b_public is public b_protected is protected b_private is not accessible
                            // c_public is public
{
public:
    int d_public;
    void showD()
    {
        cout << "D: " << d_public << endl;
    }
    D()
    {
        cout << "D constructor" << endl;
    }
};

int main()
{
    D obj;
    obj.B::a_public = 10; // to solve ambiguity between B and C we use scope resolution operator (::)
    obj.b_public = 20;
    obj.c_public = 30;
    obj.d_public = 40;
    obj.B::showA();
    obj.showB();
    obj.showC();
    obj.showD();
    return 0;
}   // main method