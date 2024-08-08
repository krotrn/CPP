#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> a(n);
    int p = 1;
    // Product before that no. 
    for (int i = 0; i < n; i++)
    {
        a[i] = p;
        p *= nums[i];
    }
    p = 1;
    // Product after that no. and multiply
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] *= p;
        p *= nums[i];
    }
    return a;
}

// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     int p1 = 1, p2 = 1, noz = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] == 0)
//             noz++;
//         p1 *= nums[i];
//         if(nums[i] != 0)
//             p2 *= nums[i];
//     }
//     if(noz>1)
//         p2 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(nums[i] == 0)
//             nums[i] = p2;
//         else
//             nums[i] = p1 / nums[i];
//     }
//     return nums;
// }

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans = productExceptSelf(v);
    for (int e : ans)
        cout << e << " ";
}