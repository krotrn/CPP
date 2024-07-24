#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);
    s.insert(11);
    s.insert(12);
    cout << s.size() << endl;
    s.erase(1);
    int target = 5;
    // s.find() returns an iterator to the element if it is found, else it returns an iterator to the end of the set
    if (s.find(target) != s.end()) // target is found
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    for (int e : s)
        cout << e << " ";
    cout << endl;
}