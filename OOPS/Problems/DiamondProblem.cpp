#include<iostream>
using namespace std;
// Diamond Problem
// The Diamond Problem is a problem that arises when two classes B and C inherit from A, and class D inherits from both B and C.

// If there is a method in A that B and C have overridden, and D does not override it, then which version of the method does D inherit: that of B, or that of C?

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
};

// class C : public A
// {
// public :
//     int c_public;
//     void showC()
//     {
//         cout << "C: " << c_public << endl;
//     }
//     C()
//     {
//         cout << "C constructor" << endl;
//     }
// };

// class B : public A
// {
// public :
//     int b_public;
//     void showB()
//     {
//         cout << "B: " << b_public << endl;
//     }
//     B()
//     {
//         cout << "B constructor" << endl;
//     }
// };
// int main()
// {
//     D obj;
//     obj.B::a_public = 10; // obj.a_public = 10; // This will give an error as it is ambiguous which a_public to access from B or C class as both are inherited from A class. So, we need to specify the class name to access the a_public variable. 
//     obj.C::a_public = 15; 
//     obj.b_public = 20;
//     obj.c_public = 30;
//     obj.d_public = 40;
//     obj.B::showA(); 
//     obj.C::showA();
//     obj.showB();
//     obj.showC();
//     obj.showD();
//     return 0;
// }



// using virtual keyword to resolve the diamond problem

// virtual keyword is used to resolve the diamond problem. It is used to avoid the duplication of data members and member functions in the derived class.
// When a class is derived from two classes and both the classes have a common base class, then the derived class will have two copies of the common base class.
// To avoid this, we use the virtual keyword while inheriting the common base class. This will avoid the duplication of the common base class in the derived class.
// The virtual keyword is used to avoid the duplication of data members and member functions in the derived class.
// When a class is derived from two classes and both the classes have a common base class, then the derived class will have two copies of the common base class.
class C : virtual public A
{
public :
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

class B : virtual public A
{
public :
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

class D : public B, public C
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
    obj.a_public = 10;  // no dublicate a_public variable will be created in D class as we have used virtual keyword in B and C class while inheriting A class.
    obj.b_public = 20;
    obj.c_public = 30;
    obj.d_public = 40;
    obj.showA();
    obj.showB();
    obj.showC();
    obj.showD();
    return 0;
}