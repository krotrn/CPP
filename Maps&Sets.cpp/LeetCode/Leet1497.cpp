#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            int rem = arr[i] % k;
            if (rem < 0) {
                rem += k;
            }
            m[rem]++;
        }
        for (auto e : m) {
            if (e.first == 0) { // divisible by k
                if (e.second % 2 != 0) { // even number of elements needed
                    return false;
                }
            } else if (2 * e.first == k) { // sum of two elements is divisible by k
                if (e.second % 2 != 0) { // even number of elements needed
                    return false;
                }
            } else {
                if (m.find(k - e.first) == m.end()) { // if the complement is not present
                    return false;
                }
                if (m[k - e.first] != e.second) { // if the frequency of the complement is not equal
                    return false;
                }
            }
        }
        return true;
    }
};