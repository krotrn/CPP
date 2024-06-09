#include<iostream>
#include<vector>
using namespace std;

int Missing(vector<int> &v)
{
    int n = v.size();
    int l = 0, h = n - 1, m = 0, ans = -1;
    while(l<=h)
    {
        m = l + ((h - l) / 2);
        if(v[m] == m)
        {
            l = m + 1;
        }
        else
        {
            ans = m;
            h = m - 1;
        }
    }
    return m;
}

int main()
{
    cout << "Enter the no. of Element : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "The smallest missing integer is : " << Missing(v);
}