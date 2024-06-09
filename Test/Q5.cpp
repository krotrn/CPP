#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no. of element in array : ";
    cin >> n;
    int a[n];
    cout << "Enter the position you want : ";
    int p;
    cin >> p;
    if (p > n || p < 0)
        return 0;
    cout << "Enter Elements in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0, t; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    cout << a[p];
}