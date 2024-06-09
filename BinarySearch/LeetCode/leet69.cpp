#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;

int Sqrt(int x)
{
    int l = 0, h = x, m = 0;
    while(l<=h)
    {
        m = l + ((h - l) / 2);
        if(((long long) (m)*(m)) <(long long) x)
        {
            l = m + 1;
        }
        else if ((long long)((m)*(m)) ==(long long) x)
        {
            return m;
        }
        else
        {
            h = m - 1;
        }

    }
    return h;
}

int main()
{
    cout << "Enter the no. which sqrt you want : ";
    int n;
    cin >> n;
    // cout << "The sqrt of integer is : " << Sqrt(n);
    cout << sqrt(n);
}