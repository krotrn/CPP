#include<iostream>
using namespace std;
class Bike {
public:
    static int noOfBike;
    int tyresize;
    int enginsize;
    Bike (int tyresize, int enginsize =200)
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