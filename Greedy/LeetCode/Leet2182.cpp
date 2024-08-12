#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> mp;
        for (char ele : s)
        {
            mp[ele]++;
        }
        string ans = "";
        int mx = 0;
        priority_queue<pair<char, int>> pq(mp.begin(), mp.end());
        while (pq.size())
        {
            auto largest = pq.top();
            pq.pop();
            int len = min(repeatLimit, largest.second);
            for (int i = 0; i < len; i++)
                ans += largest.first;
            if (largest.second > len)
            {
                pair<char,int> secondLargest;
                if(pq.size()){
                    secondLargest = pq.top();
                    pq.pop();
                    ans += secondLargest.first;
                }
                else {
                    return ans;
                }
                if(secondLargest.second>1)
                    pq.push({secondLargest.first, secondLargest.second - 1});
                pq.push({largest.first, largest.second - len});
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.repeatLimitedString("cczazcc", 3);
}
