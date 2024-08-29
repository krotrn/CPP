#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> mp;
        for (auto ele : answers)
            mp[ele]++;
        int count = 0;
        for (auto ele : mp)
        {
            if ((ele.first + 1 == ele.second) || (ele.first > ele.second))
                count += ele.first + 1;
            else{
                count += ele.first + 1;
                count += (ele.second - ele.first - 1) * (ele.first + 1);
            }
        }
        return count;
    }
};
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> mp;
        int count = 0;
        for (auto ele : answers){
            if(mp.find(ele) == mp.end()){
                count += ele + 1;   // start new group
            }
            mp[ele]++;
            // deleting the group
            if(ele + 1 == mp[ele])
                mp.erase(ele);
        }
        return count;
    }
};
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> mp;
        int result = 0;
        for (auto ele : answers){
            if(!mp[ele + 1]){
                result += ele + 1;
                if(!ele) continue;
                mp[ele + 1] = 1;
            }
            else{
                mp[ele + 1]++;
                if(ele + 1 == mp[ele + 1]){
                    mp.erase(ele + 1);
                }
            }
        }
        return result;
    }
};