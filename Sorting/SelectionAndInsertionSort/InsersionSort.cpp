#include <iostream>
#include <vector>
//Stablility -> Stable
using namespace std;
int main()
{
    cout << "Enter the no. of elements : ";
    int n;
    cin >> n;
    int a[n];

    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // for (int i = 1; i < n; i++)  // O(n^2)
    // {
    //     for (int j = i; a[j] > a[j - 1] && j > 0; j--)
    //     {
    //         if (a[j] < a[j - 1])
    //             swap(a[j], a[j - 1]);
    //         else
    //             break;
    //     }
    // }

    for (int i = 1; i < n; i++) // O(n^2)
    {
        for (int j = i; j > 0; j--)
        {

            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
            else
                break;
        }
    }

    for (int ele : a)
    {
        cout << ele << " ";
    }
}