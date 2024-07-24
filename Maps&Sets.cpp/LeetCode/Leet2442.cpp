#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int n)
    {
        int rev = 0;
        while (n)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int> &nums)
    {
        int n = nums.size();
        int rev = 0;
        for (int e : nums)
        {
            rev = reverse(e);
            nums.push_back(rev);
        }
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size();
    }
};