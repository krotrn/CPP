#include <bits/stdc++.h>
using namespace std;
int kthSmallestNo(vector<int> &v, int k) // T.C. O(nlogk) aux space O(k)
{
    // create a max heap;
    priority_queue<int> pq;
    for (int i = 0; i < v.size(); i++)// T.C. O(n)
    {
        pq.push(v[i]);// T.C. O(logk)
        // pop the maximum element
        if (pq.size() > k)
            pq.pop();// T.C. O(logk)
    }
    return pq.top();
}
// int kthSmallestNo(vector<int> &v, int k) // T.C. O(nlogn) + O(klogn) = O(nlogn)
// {
//     // create a min heap;
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for (int i = 0; i < v.size(); i++)
//         pq.push(v[i]);
//     while (k)
//     {
//         if (k == 1) return pq.top();
//         pq.pop();
//         k--;
//     }
//     return pq.top();
// }
int main()
{
    vector<int> v = {10, 2, -4, 5, 18, 24, 1, -7, 56};
    int k = 2;
    cout << kthSmallestNo(v, k) << endl;
    return 0;
}