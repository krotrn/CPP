#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter no. of element in array : ";
    cin >> n;
    int a[n];
    cout << "Enter Elements in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0, j = 0, k = n - 1, t; j <= k;)
    {
        if (a[j] == 0)
        {
            t = a[j];
            a[j] = a[i];
            a[i] = t;
            i++, j++;
        }
        else if (a[j] == 1)
            j++;
        else if (a[j] == 2)
        {
            t = a[j];
            a[j] = a[k];
            a[k] = t;
            k--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}