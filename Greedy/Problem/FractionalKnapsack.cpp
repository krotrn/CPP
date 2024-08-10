#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
   // pair<int, int> p1 = {profit[i], weight[i]};
   double r1 = (double)p1.first / p1.second;
   double r2 = (double)p2.first / p2.second;
   return r1 > r2;
}

double fractionalKnapsack(vector<int> &profit, vector<int> &weight, int capacity)
{
    /**
     * T.C : O(nlogn)
     * S.C : O(nlogn)
     */
    vector<pair<int, int>> arr;
    for (int i = 0; i < profit.size(); i++)
        arr.push_back({profit[i], weight[i]});
    sort(arr.begin(), arr.end(), cmp);
    double pro = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++){
        if(arr[i].second <= capacity){
            pro += (double)arr[i].first;
            capacity -= arr[i].second;
        }
        else{
            pro += ((double)arr[i].first / (double)arr[i].second) * capacity;
            break;
        }
    }
    return pro;
}

int main()
{
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int capacity = 50; 
    cout << fractionalKnapsack(profit, weight, capacity);
    return 0;
}