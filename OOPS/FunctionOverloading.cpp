#include<iostream>
using namespace std;


void add(int a, int b)
{
    cout << a + b << endl;
}
void add(int a, double b)
{
    cout << a + b << endl;
}
//  constructor overloading

class Bike {
public:
    int tyresize;
    int enginsize;
    Bike (int tyresize, int enginsize) : tyresize(tyresize), enginsize(enginsize){}
    Bike (int tyresize) : tyresize(tyresize), enginsize(100) {}
    Bike () :tyresize(10), enginsize(100) {}
};



int main()
{
    add(1,0.2);
    add(1,2);
}