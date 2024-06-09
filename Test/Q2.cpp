#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, min = INT_MAX, max = INT_MIN;
    cout << "Enter no. of element in array : ";
    cin >> n;
    int a[n];
    cout << "Enter Elements in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
        if (max < a[i])
            max = a[i];
    }
    cout << "Maximum is : " << max << endl
         << "Minimum is : " << min;
}