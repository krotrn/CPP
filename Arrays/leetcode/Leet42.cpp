#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int m = height[0], c = 0, q = height.size();
        vector<int> v1(q);
        vector<int> v2(q);
        v1[0] = -1, v2[q - 1] = -1;

        for (int i = 1; i < q; i++)
        {
            if (m < height[i])
                m = height[i];
            v1[i] = m;
        }
        m = height[q - 1];
        for (int i = q - 2; i >= 0; i--)
        {
            if (m < height[i])
                m = height[i];
            v2[i] = m;
        }
        vector<int> v3(q);
        for (int i = 0; i < q; i++)
        {
            v3[i] = min(v1[i], v2[i]);
        }
        for (int i = 1; i < q - 1; i++)
        {
            if (height[i] < v3[i])
            {
                c = c + v3[i] - height[i];
            }
        }
        return c;
    }
};

// 2nd approach (2 pointer approach)
class Solution{
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while(left < right){
            // if left height is smaller than right height
            // then we can trap water at left side
            if(height[left] <= height[right]){
                // if left height is greater than left_max
                // then update left_max
                // else add the difference between left_max and left height to ans
                if(height[left] >= left_max)
                    left_max = height[left];
                else
                    ans += left_max - height[left];
            }
                // if right height is greater than left height
                // then we can trap water at right side
            else{
                // if right height is greater than right_max  
                // then update right_max
                // else add the difference between right_max and right height to ans
                if(height[right] >= right_max)
                    right_max = height[right];
                else
                    ans += right_max - height[right];
            }
        }
        return ans;
        
    }
};

int main()
{
    Solution s;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(v);
}

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};