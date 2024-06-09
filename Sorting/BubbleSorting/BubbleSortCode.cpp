#include <iostream>
#include <vector>
// Bubble Sort is stable sort.
using namespace std;
int main()
{
    cout << "Enter the size : ";
    int n;
    cin >> n;
    int a[n];
    cout << "enter the array : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // // Bubble Sort  // O(n^2)
    // for (int i = 0; i < n - 1; i++)
    // {
    //     // Transverse Sort
    //     for (int j = 0; j < n-1-i; j++)
    //     {
    //         if (a[j] > a[j + 1])
    //         {
    //             swap(a[j], a[j + 1]);
    //         }
    //     }
    // }
    // cout << endl;

    // Bubble Sort optimized  // O(n)
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        flag = true;
        // Transverse Sort
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        if (flag == true){
            break;
        }
    }
    cout << endl;

    // Print
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}