#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(heights[n - 1]);
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0;i--){
            while(st.size() && st.top() < heights[i]){
                st.pop();
                ans[i]++;
            }
            if(st.size())
                ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};