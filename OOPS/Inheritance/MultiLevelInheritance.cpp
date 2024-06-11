#include<iostream>
using namespace std;

// Multilevel Inheritance
// Multilevel Inheritance is a feature of C++ where a class can inherit from a derived class, making the derived class the base class for another class.

// Eg: Class A is a base class for Class B and Class B is a base class for Class C. So, Class C is a derived class for Class B and Class B is a derived class for Class A.

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
        cout<<"A constructor"<<endl;
    }
protected:
    int a_protected;
private:
    int a_private;
    
};

class B : protected A // a_protected is protected a_private is not accessible and a_public is protected
{
public:
    int b_public;
    void showB()
    {
        cout << "B: " << b_public << endl;
    }
    B()
    {
        cout<<"B constructor"<<endl;
    }
};

class C : public B // b_public is public a_protected is protected a_private is not accessible and a_public is protected
{
public:
    int c_public;
    void showC()
    {
        cout << "C: " << c_public << endl;
    }
    void showA()
    {
        cout << "A: " << a_public << endl;
    }
    C()
    {
        cout<<"C constructor"<<endl;
    }
}; // Class C is derived from Class B and Class B is derived from Class A

int main()
{
    C obj;
    // obj.a_public = 10;
    obj.b_public = 20;
    obj.c_public = 30;
    obj.showA();
    obj.showB();
    obj.showC();
    return 0;
}