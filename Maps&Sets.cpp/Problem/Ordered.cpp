#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1); // T.C. O(logn)
    s.insert(3);
    s.insert(2);
    for (int i : s)
        cout << i << " "; // 1 2 3 sorted order
    cout << endl;
    map<int, int> m;
    m[1] = 30; // T.C. O(logn)
    m[3] = 10;
    m[2] = 20;
    for (auto i : m)
        cout << i.first << " " << i.second << endl; // 1 30 2 20 3 10 // key sorted ordered
    
    
}