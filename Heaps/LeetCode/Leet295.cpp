#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{ // T.C. O(nlogn)
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder(){
    }

    void addNum(int num){ // T.C. O(logn)
        if(left.empty() || num <= left.top())
            left.push(num); // T.C. O(logn)
        else
            right.push(num); // T.C. O(logn)
        if(left.size() > right.size() + 1){ 
            right.push(left.top());// T.C. O(logn)
            left.pop();// T.C. O(logn)
        }
        else if(right.size() > left.size()){
            left.push(right.top()); // T.C. O(logn)
            right.pop();// T.C. O(logn)
        }
    }

    double findMedian(){ // T.C. O(1)
        if(left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        return left.top();
    }
};