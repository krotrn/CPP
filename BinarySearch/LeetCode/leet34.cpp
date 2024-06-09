#include <iostream>
#include <vector>
using namespace std;

vector<int> FirstLast(vector<int> &nums, int target)
{
    int n = nums.size();
        int l = 0, h = n - 1, m = 0;
        int a = -1, b = -1;
        vector<int> v(2,-1);
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (target < nums[m])
            {
                h = m - 1;
            }
            else if (target == nums[m])
            {
                if(nums[m-1]==target)
                {
                    h = m - 1;
                }
                else
                {
                    v[0] = m;
                }
            }
            else
            {
                l = m + 1;
            }
        }
        l = 0, h = n - 1;
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (target < nums[m])
            {
                h = m - 1;
            }
            else if (target == nums[m])
            {
                if(nums[m+1]==target)
                {
                    l = m + 1;
                }
                else
                {
                    v[1] = m;
                }
            }
            else
            {
                l = m + 1;
            }
        }
        return v;
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
    vector<int> v1 = FirstLast(v, x);
    cout << "First index is : " << v1[0] << endl
         << "Last Index is : " << v1[1];
}