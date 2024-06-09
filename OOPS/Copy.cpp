#include<iostream>
using namespace std;
class Bike {
public:
    int tyresize;
    int enginsize;
    Bike (int tyresize, int enginsize)
    {
        this->tyresize = tyresize;
        this->enginsize = enginsize;
        cout << "Calling Constructor\n";
    }
    ~Bike(){
        cout << "Calling Deestructor\n";
    }
};
int main()
{
    Bike b1(100,200);
    Bike b2(b1);
    cout << b1.enginsize << endl;
    cout << b2.enginsize << endl;
    b2.enginsize++;
    cout << b1.enginsize << endl;
    cout << b2.enginsize << endl;

}