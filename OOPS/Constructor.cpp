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