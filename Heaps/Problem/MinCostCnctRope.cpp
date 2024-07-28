#include<bits/stdc++.h>
using namespace std;

int minimumCost(vector<int> &arr)
{
    // for min cost
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end()); 
    // // for max cost
    // priority_queue<int> pq(arr.begin(), arr.end()); 
    int cost = 0;
    while(pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top(); 
        pq.pop();
        cost += x + y;
        pq.push(x+y);
    }
    return cost;
} 

int main()
{
    vector<int> arr = {2, 7, 4, 1, 8};
    cout << minimumCost(arr) << endl;
    return 0;
}