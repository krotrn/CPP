#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                // if top element of pq is less than current element then break
                // because all the elements after this will be greater than the top element
                if(pq.size() >= k && pq.top() < matrix[i][j]) break;
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};