#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[digits[i]]++;
        }
        for (int i = 100; i < 999; i += 2)
        {
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = (i / 100) % 10;
            if (m.find(a) != m.end())
            {
                m[a]--;
                if (m[a] == 0)
                    m.erase(a);
                if (m.find(b) != m.end())
                {
                    m[b]--;
                    if (m[b] == 0)
                        m.erase(b);
                    if (m.find(c) != m.end())
                    {
                        m[c]--;
                        if (m[c] == 0)
                            m.erase(c);
                        ans.push_back(i);
                        m[c]++;
                        m[b]++;
                        m[a]++;
                    }
                    else
                    {
                        m[b]++;
                        m[a]++;
                    }
                }
                else
                {
                    m[a]++;
                }
            }
        }
        return ans;
    }
};