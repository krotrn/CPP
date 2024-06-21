#include <iostream>
using namespace std;
class complexNumber
{
public:
    int realNumber;
    int imagenaryNumber;
    complexNumber operator+(complexNumber c2){  // . ? : :: sizeof not allowed
        complexNumber c3;
        c3.imagenaryNumber = this->imagenaryNumber + c2.imagenaryNumber;
        c3.realNumber = this->realNumber + c2.realNumber;
        return c3;
    }
    complexNumber operator-(complexNumber c2){
        complexNumber c3;
        c3.imagenaryNumber = this->imagenaryNumber - c2.imagenaryNumber;
        c3.realNumber = this->realNumber - c2.realNumber;
        return c3;
    }
};

int main()
{
    complexNumber a1, a2, a3;
    a1.imagenaryNumber = 10;
    a1.realNumber = 5;
    a2.imagenaryNumber = 2;
    a2.realNumber = 3;
    a3 = a1 - a2;
    cout << a3.imagenaryNumber;
}