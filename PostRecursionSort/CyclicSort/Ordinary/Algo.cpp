#include <bits/stdc++.h>
using namespace std;

void CyclicSort(vector<int> &v)
{
    int i = 0, coridx;
    while (i < v.size())
    {
        coridx = v[i] - 1;
        if (i == coridx)
            i++;
        else
            swap(v[i], v[coridx]);
    }
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
    CyclicSort(v);
    for (int e : v)
    {
        cout << e << " ";
    }
}