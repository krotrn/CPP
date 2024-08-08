#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = n + sum(n - 1);
    return ans;
}

int main()
{
    cout << "Enter the no. : ";
    int n;
    cin >> n;
    cout << sum(n);
}