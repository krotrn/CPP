#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, correctIdx;
    vector<int> v;
    while (i < n)
    {
        correctIdx = nums[i] - 1;
        if (nums[correctIdx] == nums[i])
            i++;
        else
            swap(nums[correctIdx], nums[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] - 1 != i)
            v.push_back(i + 1);
    }
    return v;
}

int main()
{
    cout << "Enter the No. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans = findDisappearedNumbers(v);
    for (int e : ans)
    {
        cout << e << " ";
    }
}