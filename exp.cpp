#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0, k = 1; i < n; i++)
    {
        if(i==k)
        {
            cout << endl;
            k++;
            i = 0;
        }
        cout << "*";
    }
}