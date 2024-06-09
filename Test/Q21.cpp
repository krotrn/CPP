#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the no. of elements : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    int a[n], sum = 0;
    bool t = false;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += a[j];
        }
        if (sum == 0)
        {
            t = true;
            break;
        }
    }
    if (t == true)
        cout << "True";
    else
        cout << "False";
}