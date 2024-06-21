#include<iostream>
using namespace std;

class A 
{
private:
    int a_private = 10;
public:
    friend void pri(A a);
};

class B: public A {};
void pri(A a){
    cout << a.a_private << endl;
}

int main()
{
    A a;
    pri(a);
}