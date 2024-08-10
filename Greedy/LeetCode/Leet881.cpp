#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /**
         * Time : O(nlogn)
         * Space : O(sort)
         */
        sort(people.begin(), people.end());
        int boats = 0;
        int i = 0, j = people.size() - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit)
                i++;
            j--;
            boats++;
        }
        return boats;
    }
};