#include <iostream>
#include <vector>
#include <climits>
// o(n*log(sum-max))
using namespace std;

bool check(vector<int> &v, int d, int c)
{
    int n = v.size();
    int m = c;
    int count = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (m >= v[i])
        {
            m -= v[i];
        }
        else
        {
            count++;
            m = c;
            m -= v[i]; 
        }
    }

    if (count <= d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int shipWithinDays(vector<int> &weights, int days)
{
    int max = INT_MIN;
    int sum = 0;
    for (int e : weights)
    {
        if (max < e)
        {
            max = e;
        }
        sum += e;
    }
    int l = max, h = sum, m, mid = sum;
    while (l <= h)
    {
        m = l + ((h - l) / 2);
        if (check(weights, days, m))
        {
            mid = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return mid;
}

int main()
{
    cout << "Enter the no. of Packages : ";
    int n;
    cin >> n;
    cout << "Enter the Weights : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Enter the no. of Days : ";
    int d;
    cin >> d;
    cout << "The minimum capacity is : " << shipWithinDays(v, d);
}