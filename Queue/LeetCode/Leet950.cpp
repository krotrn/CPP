#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};

int main(){
    Solution a;
    vector<int> deck = {17,13,11,2,3,5,7};
    vector<int> ans = a.deckRevealedIncreasing(deck);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}