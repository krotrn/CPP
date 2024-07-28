#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) { // T.C. O(nlogn)
        priority_queue<int> pq(stones.begin(), stones.end()); // T.C. O(nlogn) 
        // priority_queue<int> pq;
        // for(auto e: stones)
        //     pq.push(e);
        while(pq.size() > 1){ // T.C. O(nlogn)
            int x = pq.top();
            pq.pop(); // T.C. O(logn)
            int y = pq.top();
            pq.pop(); // T.C. O(logn)
            if(x != y)
                pq.push(abs(x-y)); // T.C. O(logn)
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};