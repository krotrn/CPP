#include <iostream>
#include <climits>
// Stability -> Unstable
using namespace std;
// O(n^2)
int main()
{

    cout << "Enter the no of element : ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Selection sort  
    for (int i = 0; i < n - 1; i++)
    {
        int min = INT_MAX;
        int mindx = -1;
        for (int j = i; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                mindx = j;
            }
        }
        swap(a[i], a[mindx]);
    }
    // int m = a[0], c = -1, t;
    // for (int i = 0; i < n; i++)
    // {
    //     if (m > a[i])
    //     {
    //         m = a[i];
    //         t = i;
    //     }
    //     if (i == n - 1)
    //     {
    //         c++;
    //         i = c;
    //         swap(a[t], a[i]);
    //         m = a[i + 1];
    //     }
    // }
    for (int e : a)
    {
        cout << e << " ";
    }
}