#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxiProfit = 0;
        for (int i = 0; i < prices.size(); i++){
            mini = min(mini, prices[i]);
            maxiProfit = max(maxiProfit, prices[i] - mini);
        }
        return maxiProfit;
    }
};

