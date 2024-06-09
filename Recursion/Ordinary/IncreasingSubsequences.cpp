#include <all>

void subset(vector<int> &arr, int idx, vector<int> ans, vector<vector<int>> &v, int k)
{
    if (ans.size() > k) //  for overflow
    {
        return;
    }
    if (idx == -1)
    {
        if (ans.size() < k) return;     //  for underflow
        sort(ans.begin(), ans.end());
        v.push_back(ans);
        return;
    }
    if(ans.size() + idx + 1 < k) return;    //  checking rest
    subset(arr, idx - 1, ans, v, k);
    ans.push_back(arr[idx]);
    subset(arr, idx - 1, ans, v, k);
}

vector<vector<int>> subsets(vector<int> &nums, int k)
{
    vector<vector<int>> v;
    vector<int> t;
    subset(nums, nums.size() - 1, t, v, k);
    sort(v.begin(), v.end());
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
    cout << "Enter the no. of subsequences : ";
    int k;
    cin >> k;
    vector<vector<int>> a = subsets(v, k);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}