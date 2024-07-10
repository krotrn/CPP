#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

vector<int> firstNegativeInEachWindowK(vector<int>& arr, int k) {
    vector<int> ans;
    queue<int> q;
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0){
            q.push(i);
        }
    }
    int i = 0;
    while(i+k<=n)
    {
        while(q.size() && q.front()<i) q.pop();
        if(q.size()==0 || q.front()>i+k-1) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
        i++;
    }
    return ans;
}

int main(){
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> ans = firstNegativeInEachWindowK(arr, k);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}