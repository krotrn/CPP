#include<bits/stdc++.h>
using namespace std;
void kSortedArray(vector<int> &v, int k) // T.C. O(nlogk) aux space O(k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // (min heap)
    queue<int> q;
    // int idx = 0;
    for (int i = 0; i < v.size(); i++) // T.C. O(n)
    {
        pq.push(v[i]); // T.C. O(logk)
        if (pq.size() > k)
        {
            // inserting the top element of the min heap to the right place in the array
            // v[idx++] = pq.top();
            v[i-k] = pq.top();// T.C. O(1)
            pq.pop(); // T.C. O(logk)
        }
    }
    // inserting the remaining elements of the min heap to the right place in the array
    int i = v.size()-pq.size();
    while (!pq.empty()) // T.C. O(k)
    {
        // v[idx++] = pq.top();
        v[i++] = pq.top(); // T.C. O(1)
        pq.pop(); // T.C. O(logk)
    }
}
int main()
{
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    kSortedArray(v, k);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}