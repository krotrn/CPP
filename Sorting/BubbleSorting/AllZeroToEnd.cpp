#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    cout << "Enter the numbers : ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        flag = true;
        // Transverse Sort
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j] == 0 && a[j + 1] != 0)
            {
                swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        if (flag == true){
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
}