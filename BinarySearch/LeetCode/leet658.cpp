#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// O(klog(k)+log(n));
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    vector<int> v(k);
    if(x<arr[0])
    {
        for (int i = 0; i < k; i++)
        {
            v[i] = arr[i];
        }
        return v;
    }
    if (x>arr[n-1])
    {
        for (int i = 0; i < k; i++)
        {
            v[k-i-1] = arr[n - i - 1];
        }
        return v;
    }
    int l = 0, h = n - 1, m = -1;
    int t = 0;
    bool flag = false;
    while (l <= h)
    {
        m = l + ((h - l) / 2);
        if (x == arr[m])
        {
            v[t] = x;
            flag = true;
            t++;
            break;
        }
        else if (x < arr[m])
            h = m - 1;
        else
            l = m + 1;
    }
    int lb, ub;
    if(flag==false)
    {
        lb = h;
        ub = l;
    }
    else
    {
        lb = m - 1;
        ub = m + 1;
    }
    while (t < k && lb >= 0 && ub < n)
    {
        int a = abs(arr[lb] - x);
        int b = abs(arr[ub] - x);
        if(a<=b)
        {
            v[t] = arr[lb];
            lb--;
            t++;
        }
        else
        {
            v[t] = arr[ub];
            ub++;
            t++;
        }
    }
    while(t<k)
    {
        if(ub==n)
        {
            v[t] = arr[lb];
            lb--;
            t++;
        }
        else if(lb=-1)
        {
            v[t] = arr[ub];
            ub++;
            t++;
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;

    cout << "Enter the array : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter the k : ";
    int k;
    cin >> k;

    cout << "Enter the x : ";
    int x;
    cin >> x;

    vector<int> v1 = findClosestElements(v, k, x);
    cout << "Result is : " << endl;
    for (int el : v1)
    {
        cout << el << " ";
    }
}