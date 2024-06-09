#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;
    cout << "Enter the elements : " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int c, k = 0; // from here copied from kaushal
    cout << "The dublicate Elements are : " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j] && a[j] != 0)
            {
                k++;
                a[j] = 0;
            }
        }
        if (k > 1)
            cout << a[i] << " is " << k << " times" << endl;
        k = 1;
    }
}