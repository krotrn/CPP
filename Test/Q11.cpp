#include <iostream>
using namespace std;
void rev(int a[], int x, int y)
{
    for (int i = x, j = y, t; i <= j; i++, j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
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
    rev(a, 0, n - 1);
    rev(a, 1, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}