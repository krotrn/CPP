#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
        return 0;
    int i = 0;
    int j = 0;
    int p = 1;
    int num = 0;
    while (j<nums.size())
    {
        p *= nums[j];
        while(p>=k)
        {
            num += j - i;
            p /= nums[i++];
        }
        j++;
    }
    while(i<nums.size())
    {
        num += j - i;
        p /= nums[i++];
    }
    return num;
}

int main()
{
    cout << "Enter the no. of Element : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Enter the K : ";
    int k;
    cin >> k;
    cout << "The No. of Subarray in which product is lessthen K : " << numSubarrayProductLessThanK(v, k);
}