#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        unordered_map<int, int> mp;

        // ordering the array without dublicating
        set<int> pq(arr.begin(), arr.end()); 

        // maping with respect to position
        int j = 1;
        for (int i : pq)
            mp[i] = j++;

        // update the array
        for (int i = 0; i < arr.size(); i++)
            arr[i] = mp[arr[i]];
    }
};


class Solution{
public:
    vector<int> arrayRankTransform(vector<int> &arr){
        if (arr.empty()) return arr;

        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;
        int r = 1;
        for (int i : sorted){
            if (mp.find(i) == mp.end())
                mp[i] = r++;
        }

        for (int &i : arr)
            i = mp[i];

        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> ar1 = {1, 3, 2, 3, 5, 7, 6, 6};
    vector<int> arr = s.arrayRankTransform(ar1);
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}