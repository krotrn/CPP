#include <iostream>
#include <vector>
using namespace std;

int Occurance(vector<int> &nums, int target)
{
    int n = nums.size();
    int l = 0, h = n - 1, m;
    int a = -1, b = 0;
    while (l <= h)
    {
        m = l + ((h - l) / 2);
        if (target < nums[m])
        {
            l = m + 1;
        }
        else if (target == nums[m])
        {
            if (m != 0)
            {
                if (target != nums[m - 1])
                {
                    a = m;
                    break;
                }
                else
                {
                    h = m-1;
                }
            }
            else
            {
                a = m;
                break;
            }
            if (m != n - 1)
            {
                if (nums[m + 1] != target)
                {
                    b = m;
                }
            }
            else
            {
                b = m;
            }
        }
        else
        {
            h = m - 1;
        }
    }
    if (b < 0 && a >= 0)
    {
        l = a, h = n - 1;
        while (l <= h)
        {
            m = l + ((h - l) / 2);
            if (target < nums[m])
            {
                l = m + 1;
            }
            else if (target == nums[m])
            {
                if (m != n - 1)
                {
                    if (target != nums[m + 1])
                    {
                        b = m;
                        break;
                    }
                    else
                    {
                        l = m+1;
                    }
                }
                else
                {
                    b = m;
                    break;
                }
            }
            else
            {
                h = m - 1;
            }
        }
    }
    return b - a + 1;
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
    cout << "The no. Occurance of " << x << " is : " << Occurance(v, x);
}