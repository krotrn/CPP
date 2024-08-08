#include <bits/stdc++.h>
using namespace std;

int swapping(vector<int> &v, int s, int e)
{
    int pvt = (s + e) / 2;
    int c = 0;
    for (int i = s; i <= e; i++)
    {
        if (i == pvt)
            continue;
        if (v[i] <= v[pvt])
            c++;
    }
    int pivotIdx = s + c;
    swap(v[pvt], v[pivotIdx]);
    int i = s, j = e;
    while (i < pivotIdx && j > pivotIdx)
    {
        if (v[pvt] <= v[i])
        {
            if (v[pvt] > v[j])
                swap(v[i++], v[j--]);
            else
                j--;
        }
        else
            i++;
    }
    return pivotIdx;
}

int QuickSelect(vector<int> &v, int s, int e, int k)
{
    int c = swapping(v, s, e);
    if (c + 1 == k)
        return v[c];
    else if (c + 1 > k)
        return QuickSelect(v, s, c - 1, k);
    else
        return QuickSelect(v, c + 1, e, k);
}

void Quicksort(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    //  swaping lesser element then pivot to left from right and higher element then pivot to left
    int c = swapping(v, s, e);

    //   recursion
    Quicksort(v, s, c - 1);
    Quicksort(v, c + 1, e);
    return;
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
    cout << "Enter the index : ";
    int k;
    cin >> k;
    cout << QuickSelect(v, 0, n - 1, k) << endl;
    Quicksort(v, 0, n - 1);
    for (int e : v)
    {
        cout << e << " ";
    }
}