#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int> &arr)
{
    int n = arr.size();
    int l = 0, h = n - 1, m;
    while(l<=h)
    {
        m = l + ((h - l) / 2);
        if (arr[m - 1] < arr[m])
        {
            if(arr[m] < arr[m + 1])
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        else
        {
            if(arr[m] > arr[m + 1])
            {
                h = m - 1;
            }
            else
            {
                return m;
            }
        }
        return -1;
    }
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Peak Index is : " << peak(v);
}