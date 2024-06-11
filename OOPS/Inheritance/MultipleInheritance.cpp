#include<iostream>
using namespace std;
// Multiple Inheritance
// Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.
// In Multiple Inheritance, a class can inherit from more than one classes.
// The derived class inherits all the features of the base classes.
// The derived class can access the features of all the base classes.
// The derived class can access the features of the base classes using the scope resolution operator (::).
// The derived class can access the features of the base classes using the object of the derived class.
// The derived class can access the features of the base classes using the object of the base class.

// eg: Class A and Class B are base classes for Class C. So, Class C is a derived class for Class A and Class B.

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

class B // a_protected is protected a_private is not accessible and a_public is public
{
    public:
        int b_public;
        void showB()
        {
            cout << "B: " << b_public << endl;
        }
        B()
        {
            b_public = 20;
            cout<<"B constructor"<<endl;
        }
    protected:
        int b_protected;
    private:
        int b_private;
};

class C : public A, public B // a_protected is protected a_private is not accessible and a_public is public
                            // b_public is public b_protected is protected b_private is not accessible
                            // c_public is public
{
    public:
        int c_public;
        void showC()
        {
            cout << "C: " << c_public << endl;
        }
        C()
        {
            cout<<"C constructor"<<endl;
        }
};
int main()
{
    C obj;
    obj.a_public;
    obj.b_public;
    obj.c_public;
    obj.showA();
    obj.showB();
    obj.showC();
    return 0;
}