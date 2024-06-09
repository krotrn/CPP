#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the no. of train : ";
    int n;
    cin >> n;
    float a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time of train " << i + 1 << " : " << endl;
        cin >> a[i];
        cout << "Enter the departure time : " << endl;
        cin >> b[i];
    }
    cout << " ";
}