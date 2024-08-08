#include <bits/stdc++.h>
using namespace std;
void com(vector<int> ans, vector<int> &candidates, int target, int idx, vector<vector<int>>& v)
{
    if (target == 0)
    {
        v.push_back(ans);
        return;
    }
    else if (target < 0) return;
    for (int i = idx; i < candidates.size(); i++)
    {
        ans.push_back(candidates[i]);
        com(ans, candidates, target - candidates[i],i, v);
        ans.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> v;
    vector<int> v1;
    com(v1, candidates, target, 0, v);
    return v;
}
int main()
{
    cout << "Enter the no. of element : ";
    int n;
    cin >> n;
    cout << "Enter the element : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Enter the Target : ";
    int x;
    cin >> x;
    vector<vector<int>> a = combinationSum(v, x);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}