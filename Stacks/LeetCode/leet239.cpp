#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
               int n = nums.size();
        if(n==1) return nums;
        vector<int> nxtGrIdx(n);
        stack<int> st;
        nxtGrIdx[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() && nums[st.top()] <= nums[i])
                st.pop();
            if (st.size() != 0)
                nxtGrIdx[i] = st.top();
            else
                nxtGrIdx[i] = n;
            st.push(i);
        }
        vector<int> ans(n - k + 1);
        int j = 0;
        for(int i = 0; i < n - k + 1; i++){
            if(j<i)
                j = i;
            int mx = ans[j];
            while(j<i+k){  // nextGreaterEle idside the window
                mx = nums[j];
                if(nxtGrIdx[j] >= i+k)
                    break;
                j = nxtGrIdx[j];
            }
            ans[i] = mx;
        }
        return ans;
    }
};