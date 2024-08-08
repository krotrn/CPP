#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &v)
{
    int n = v.size();
    int i = 0, correctIdx;
    while (i < n)
    {
        correctIdx = v[i];
        if (v[correctIdx] == v[i])
            return v[i];
        else
            swap(v[correctIdx], v[i]);
    }
    return 1000;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
}