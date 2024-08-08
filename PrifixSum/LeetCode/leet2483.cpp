#include <bits/stdc++.h>
using namespace std;
int bestClosingTime(string customers)
{
    int n = customers.length();
    vector<int> a(n + 1);   // for calculating N before i
    vector<int> b(n + 1);   // for calculating Y after i
    // calculating i
    a[0] = 0;
    for (int i = 0; i < n; i++)
    {
        a[i + 1] = a[i] + (customers[i]=='N');
    }

    // calculating Y and Addition
    b[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        b[i] = b[i+1] + (customers[i] == 'Y');
        a[i] += b[i];
    }

    // checking minimum
    int min = INT_MAX;
    int idx = 0;
    for (int i = 0; i <= n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            idx = i;
        }
    }
    return idx;
}

int main()
{
    cout << "Enter the String : ";
    string s;
    cin >> s;
    cout << "The Best Closing Time is :" << bestClosingTime(s);
}