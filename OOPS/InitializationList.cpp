#include<iostream>
using namespace std;
class Bike {
public:
    int tyresize;
    int enginsize;
    Bike (int tyresize, int enginsize) : tyresize(tyresize),enginsize(enginsize){}
};


int main()
{
    Bike re(20, 200);
    Bike b(15, 150);
    cout << re.tyresize << " " << re.enginsize << endl;
    cout << b.tyresize << " " << b.enginsize << endl;
}