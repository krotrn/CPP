#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int n = senate.size();
        int i = 0;
        while(i<n)
        {
            q.push(i);
            i++;
        }
        
    }
};
