#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        // total number of groups
        int noOfGroups = n / 2;

        // sum of all elements
        int sum = accumulate(skill.begin(), skill.end(), 0);

        // skill per group
        int sumPerGroup = sum / noOfGroups;

        // if sum cannot divide into groups
        if (sum % noOfGroups != 0)
            return -1;

        // {element, count}
        unordered_map<int, int> mp;

        // count of each element
        for (int i = 0; i < n; i++)
            mp[skill[i]]++;

        long long ans = 0;
        for (int i = 0; i < n; i++){
            // x + y = sumPerGroup
            int x = skill[i];
            int y = sumPerGroup - x;

            // if x has already been paired, skip it
            if (mp[x] == 0) 
                continue;

            // if y is present in map and count > 0 then we can form a group
            if (mp[y] > 0){

                if (x == y && mp[x] < 2) {
                    return -1;
                }
                ans += (long long)(x * y);
                mp[x]--;
                mp[y]--;
            }else // if y is not present in map there is no possible group for x
                return -1;
        }
        return ans;
    }
};

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        
        // Sort the skill array
        sort(skill.begin(), skill.end());

        // Calculate the total sum and the target sum per group
        int sum = accumulate(skill.begin(), skill.end(), 0);
        int noOfGroups = n / 2;

        // Each group should have this sum
        int sumPerGroup = sum / noOfGroups;

        // If sum can't be divided evenly into groups, return -1
        if (sum % noOfGroups != 0) {
            return -1;
        }

        long long ans = 0;
        int l = 0, h = n - 1;

        // Use two pointers to form pairs
        while (l < h) {
            int currentSum = skill[l] + skill[h];
            
            // If the sum of the two players doesn't match the required sum
            if (currentSum != sumPerGroup) {
                return -1;
            }

            // Add the chemistry (product of their skills) to the answer
            ans += (long long)(skill[l] * skill[h]);

            // Move the pointers
            l++;
            h--;
        }

        return ans;
    }
};


auto speedup = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
};