/*Given an array, arr[] containing 'n' integers,
the task is to find an integer (say K) such that after replacing each and every index of the array by
la¡ – KI where (i ∈ [1, n]), results in a sorted array.
If no such integer exists that satisfies the above condition then return -1.*/
#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;
tuple<float, float> Range(vector<float> &v)
{
    int n = v.size();
    float a = (float)INT_MIN, b = (float)INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] < v[i + 1])
        {
            b = min(b, ((v[i] + v[i + 1]) / 2));
        }
        else
        {
            a = max(a, ((v[i] + v[i + 1]) / 2));
        }
    }
    return make_tuple(a, b);
}
int main()
{
    cout << "Enter the no. of elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<float> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    float a, b;
    tie(a, b) = Range(v);
    if (a >= b)
    {
        if (a == b && a == (int)a)
        {
            cout << "The no. of Sorting is : " << (int)a;
        }
        else
        {
            cout << -1;
        }
        return 0;
    }

    if (a - (int)a > 0)
    {
        a = (int)a + 1;
    }
    cout << "The Range Of Sorting is : "
         << "(" << a << "," << b << ")";
}