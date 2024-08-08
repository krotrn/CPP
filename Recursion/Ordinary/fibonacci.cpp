#include <bits/stdc++.h>
using namespace std;
int fib(int n) //   T.C = O(2^n)
{
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    cout << "Enter the no. : ";
    int n;
    cin >> n;
    cout << fib(n);
}