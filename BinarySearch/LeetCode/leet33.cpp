#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &nums,int target)
{
    int n = nums.size();
    int l = 0, h = n - 1, m = 0;
    int idx = -1;
    if(n==0) return idx;
    else if(n==1)
        {
            if(nums[0]==target)
            {
                return 0;
            }
            else return idx;
        }
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if(nums[m]==target)
        {
            return 0;
        }
        else if (nums[m] < nums[m + 1] && nums[m] < nums[m - 1])
        {
            idx = m;
            break;
        }
        else if (nums[m] > nums[m + 1] && nums[m] > nums[m - 1])
        {
            idx = m + 1;
            break;
        }
        else if (nums[m] > nums[h])
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    if (idx == -1)
    {
        l = 0, h = n - 1;
    }
    else if (nums[0] <= target && nums[idx - 1] >= target)
    {
        l = 0, h = idx - 1;
    }
    else
    {
        l = idx, h = n - 1;
    }

    while(l<=h)
    {
        m = l + ((h - l) / 2);
        if (target == nums[m])
            return m;
        else if (target < nums[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main()
{
    cout << "Enter the no. of Element : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Enter the Target : ";
    int x;
    cin >> x;
    cout << "it's index is : " << search(v, x);
}