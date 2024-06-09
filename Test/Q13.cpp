#include <iostream>
using namespace std;
int main()
{
    cout << "Enter no. of elements : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target element : ";
    int k;
    cin >> k;
    int c = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                c++;
            }
        }
    }
    cout << "No. of pair is : " << c;
}