#include<iostream>
#include<vector>
using namespace std;

int FirstOccuance(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, h = n - 1, m,a,b;
    while(l<=h)
    {
        m = l + ((h - l) / 2);
        if(target<nums[m])
        {
            h = m - 1;
        }
        else if (target == nums[m])
        {
            if (target == nums[m + 1])
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
        else
        {
            l = m + 1;
        }
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
    cout << "The First Occurance of " << x << " is : " << FirstOccuance(v, x);
}