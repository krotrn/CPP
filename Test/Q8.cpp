#include <iostream>
using namespace std;
int main()
{
    int n;
    bool k = true;
    cout << "Enter no. of element in array : ";
    cin >> n;
    int a[n];
    cout << "Enter the sum you want : ";
    int p;
    cin >> p;
    cout << "Enter Elements in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0, t; i < n; i++)
    {
        t = a[i];
        if (t == p)
        {
            cout << "Sum found at " << i << endl;
        }
        else
        {
            for (int j = i + 1; j < n; j++)
            {
                t += a[j];
                if (t == p)
                {
                    cout << "Sum in between " << i << " " << j << endl;
                    k = false;
                }
            }
        }
    }
    if (k == true)
        cout << "doesnot exist";
}