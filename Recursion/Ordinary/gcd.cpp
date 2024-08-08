#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) //  O(log(a+b))
{
    if(a==0) return b;
    gcd(b % a, a);
}

int main()
{
    cout << "Enter the no.s : ";
    int a, b;
    cin >> a >> b;
    cout << "The gcd is : " << gcd(a, b);
}