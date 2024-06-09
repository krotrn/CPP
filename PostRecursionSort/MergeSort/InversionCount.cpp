#include<all>
//  T.C = O(nlog(n))    S.C =(n)
int Inversioncount(vector<int>& a,vector<int>& b)
{
    int count = 0, i = 0, j = 0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<b[j])
        {
            count += (a.size() - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return count;
}
void merge(vector<int>& a,vector<int>& b, vector<int>& v)
{
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if(a[i]<=b[j])
            v[k++] = a[i++];
        else
            v[k++] = b[j++];
    }
    if (i == a.size()) while(j<b.size())
            v[k++] = b[j++];
    else if (j == b.size()) while (i < a.size())
            v[k++] = a[i++];
}

int mergesort(vector<int>& v)
{
    int count = 0;
    int n = v.size();
    if(n==1)
        return 0;
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < max(n1,n2); i++)
    {
        if(i<n1)
            a[i] = v[i];
        if(i<n2)
            b[i] = v[n1+i];
    }
    count += mergesort(a);
    count+= mergesort(b);

    count += Inversioncount(a, b);

    merge(a, b, v);
    a.clear();
    b.clear();
    return count;
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
    cout << mergesort(v);
    cout << endl;
    for (int i=0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}