#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        int openCount = 0, closeCount = 0, swaps = 0;
        int i = 0, j = n - 1;

        // Find the first closing bracket from the end
        while (s[j] != '[')
            j--;

        while (i < j)
        {
            if (s[i] == '[')
            {
                openCount++;
            }
            else
            {
                closeCount++;
            }

            // If there are more closing brackets than opening brackets
            if (closeCount > openCount)
            {
                swap(s[i], s[j]);
                swaps++;
                closeCount--;

                // Find the next opening bracket from the end
                while (s[j] != '[')
                    j--;
            }
            else
            {
                i++;
            }
        }

        return swaps;
    }
};
class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.length();
        int swaps = 0;
        int unbalancedOpening = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ']')
            {
                if (!unbalancedOpening)
                {
                    swaps++;
                    unbalancedOpening++;
                }
                else
                {
                    unbalancedOpening--;
                }
            }
            else
            {
                unbalancedOpening++;
            }
        }

        return swaps;
    }
};

auto speedup = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};