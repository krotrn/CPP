#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target) 
// O(log(n))
{
    int l = 0, h = nums.size() - 1, m = 0;
    while (l <= h)
    {
        m = l + ((h - l) / 2);      // for exceeding INT_MAX 
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
    cout << "Enter the no. Of Elements : ";
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
    cout << "Index is : " << search(v, x);
}