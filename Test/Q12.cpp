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
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int s = n * (n + 1) / 2;
    cout << s - sum;
}