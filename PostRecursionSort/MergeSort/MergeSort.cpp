#include<bits/stdc++.h>
using namespace std;
//  T.C = O(nlog(n))
void merge(vector<int> &a, vector<int> &b, vector<int> &v)
{
    int i = 0, j = 0, k = 0;
    while(j<a.size() && k<b.size())
    {
        if (a[j] <= b[k])
            v[i++] = a[j++];
        else
            v[i++] = b[k++];
    }
    if(j==a.size()){
        while(k<b.size())
        {
             v[i++] = b[k++];
        }
    }
    
    if(k==b.size()){
        while(j<a.size())
        {
             v[i++] = a[j++];
        }
    }
       
}

void mergesort(vector<int> &v)
{
    int n = v.size();
    if(n==1)
        return;
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = v[i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = v[n1+i];
    }
    //  S.C = O(nlog(n))
    mergesort(a);
    mergesort(b);
 
    merge(a, b, v);
    //  S.C = O(n)
    a.clear();
    b.clear();
}

int main()
{
    cout << "Enter the no. of elements : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    vector<int> v(n);
    for (int i=0; i < n; i++)
    {
        cin >> v[i];
    }
    mergesort(v);
    for (int i=0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}