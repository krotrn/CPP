#include <bits/stdc++.h>
using namespace std;
vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    int m = queries.size();
    sort(nums.begin(), nums.end());
    vector<int> ans(m);
    int a, lo, hi, mid;
    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        a = 0;
        lo = 0, hi = n - 1;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (queries[i] < nums[mid])
                hi = mid - 1;
            else
            {
                a = mid + 1;
                lo = mid + 1;
            }
        }
        ans[i] = a;
    }
    return ans;
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

    cout << "Enter the no. of Queries : ";
    int m;
    cin >> m;
    cout << "Enter the Queries : " << endl;
    vector<int> q(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }

    vector<int> a = answerQueries(v, q);
    for (int e : a)
        cout << e << " ";
}