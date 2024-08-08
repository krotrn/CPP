#include <bits/stdc++.h>
using namespace std;
auto fac(int n) 
{
    // base case
    if(n==0)
    {
        return 1;
    }
    return n * fac(n - 1);
}
int main() 
{
    int n;
    cin >> n;   
    cout << fac(n);
}