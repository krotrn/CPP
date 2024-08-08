#include <bits/stdc++.h>
using namespace std;
//  T.C = O(nlog(n)) S.C
int swaping(vector<int> &v, int s, int e)
{
    //  finding pivot index = right place of element in array
    int pvt = v[(s + e) / 2];
    int c = 0;
    for (int i = s; i <= e; i++)
    {
        if (i == (s + e) / 2)
            continue;
        if (pvt >= v[i])
            c++;
    }
    // swap to first index
    int pivotIdx = s + c;
    swap(v[(s + e) / 2], v[pivotIdx]);
    int i = s, j = e;

    while (i < pivotIdx && j > pivotIdx)
    {
        if (v[i] <= pvt)
            i++;
        if (v[j] > pvt)
            j--;
        else if(v[i]>pvt && v[j]<=pvt)
        {
            swap(v[i++], v[j--]);
        }
    }
    return (pivotIdx);
}

void Quicksort(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    //  swaping lesser element then pivot to left from right and higher element then pivot to left
    int c = swaping(v, s, e);

    //   recursion 
    Quicksort(v, s, c - 1);
    Quicksort(v, c + 1, e);
    return;
}

int main()
{
    cout << "Enter the No. of Element : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Quicksort(v, 0, n - 1);
    for (int e : v)
    {
        cout << e << " ";
    }
}