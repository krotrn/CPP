#include <bits/stdc++.h>
using namespace std;
void subset(vector<int> &arr, int idx, vector<int> ans, vector<vector<int>> &v)
{
    if(idx==-1)
    {
        sort(ans.begin(), ans.end());
        v.push_back(ans);
        return;
    }
    subset(arr, idx - 1, ans,v);
    ans.push_back(arr[idx]);
    subset(arr, idx - 1, ans,v);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> v;
    vector<int> t;
    subset(nums, nums.size() - 1, t,v);
    return v;
}
int main()
{
    cout << "Enter the no. of element : ";
    int n;
    cin >> n;
    cout << "Enter the element : " << endl;
    vector<int> v(n);
    for (int i = 0;i < n;i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> a=subsets(v);
    for (int i = 0;i < a.size();i++)
    {
        for (int j = 0;j < a[i].size();j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}