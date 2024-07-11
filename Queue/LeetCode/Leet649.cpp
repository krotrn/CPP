#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> q, r, d;
        int n = senate.size();
        for (int i = 0; i < n; ++i)
        {
            q.push(i);
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (!r.empty() && !d.empty())
        {
            int radiantIndex = r.front(), direIndex = d.front();
            r.pop();
            d.pop();
            if (radiantIndex < direIndex)
            {
                // Radiant senator bans Dire senator
                r.push(radiantIndex + n); // Radiant gets another turn in future rounds
            }
            else
            {
                // Dire senator bans Radiant senator
                d.push(direIndex + n); // Dire gets another turn in future rounds
            }
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};

int main()
{
    Solution a;
    cout << a.predictPartyVictory("DRDDRRRDDDDDRRRRRRRRDDDDDDDDDDDDDRRRRRRRRRRRRRRRRRRRRRDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD") << "\n";
    return 0;
}