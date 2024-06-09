#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the no. of elements : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1])
        {
            cout << a[i] << endl;
            break;
        }
        if (i == n - 1)
            cout << a[i];
    }
}