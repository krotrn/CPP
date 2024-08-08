#include <bits/stdc++.h>
using namespace std;
// int longestSubarray(vector<int> &nums)
// {
//     int i = 0;
//     int j = 0;
//     int maxlen = 0;
//     int z = 0;
//     while (j < nums.size())
//     {
//         if (nums[j] == 0)
//             z++;
//         if (z > 1)
//         {
//             while (nums[i] && i <= j)
//                 i++;
//             i++;
//             z--;
//         }
//         j++;
//         maxlen = max(maxlen, j - i - 1);
//     }
//     return maxlen;
// }

int longestSubarray(vector<int> &nums)
{
    int zeroPos = -1;
    int i = 0;
    int j = 0;
    int maxLen = 0;
    int count = 0;
    while (j < nums.size())
    {
        int prev = zeroPos;
        if (nums[j] == 0)
        {
            count++;
            zeroPos = j;
        }
        if (count <= 1)
            j++;
        else
        {
            maxLen = max(maxLen, j - i);
            i = prev + 1;
            count--;
            j++;
        }
    }
    maxLen = max(maxLen, j - i);
    return maxLen - 1;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "The longest one's is : " << longestSubarray(v);
}