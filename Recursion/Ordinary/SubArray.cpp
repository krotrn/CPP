#include<all>
//  in unique elements only
void subarr( vector<int> ans, vector<int> &arr, int idx, vector<vector<int>> &v)
{
    if(idx==arr.size())
    {
        v.push_back(ans);
        return;
    }
    subarr(ans, arr, idx + 1, v);
    if (ans.size() == 0 || ans[ans.size() - 1] == arr[idx - 1])
    {
        ans.push_back(arr[idx]);
        subarr(ans, arr, idx + 1, v);
    }
    return;
}
vector<vector<int>> subarray(vector<int>& v)
{
    vector<int> v1;
    vector<vector<int>> a;
    subarr(v1, v, 0, a);
    return a;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "enter the elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n;i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> a = subarray(v);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}