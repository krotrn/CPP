#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> prevSmallerIdx(vector<int> &v)
    {
        stack<int> st;
        int n = v.size();
        vector<int> ans(n);
        ans[0] = -1;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (st.size() && v[st.top()] >= v[i])
                st.pop();
            if (st.size() != 0)
                ans[i] = st.top()  ;
            else
                ans[i] = -1;

            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerIdx(vector<int> &v)
    {
        stack<int> st;
        int n = v.size();
        vector<int> ans(n);
        ans[n - 1] = n;
        st.push(n-1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() && v[st.top()] >= v[i])
                st.pop();
            if (st.size() != 0)
                ans[i] = st.top();
            else
                ans[i] = n;
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> prev = prevSmallerIdx(heights);
        vector<int> next = nextSmallerIdx(heights);
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++){
            int area = heights[i] * (next[i] - prev[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};