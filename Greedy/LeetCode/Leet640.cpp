#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // for easy swaping and indexing
        string st = to_string(num);
        // index = digit
        // v[index] = last appearance
        vector<int> v(10, -1);
        for (int i = 0; i < st.size(); i++)
            v[st[i] - '0'] = i;
        // iterate through each number
        for (int i = 0; i < n; i++){
            // if larger digit appeared after current index then swap
            for (int j = 9; i > v[i] - '0'; j--){
                if(v[j] > i){
                    swap(st[i], st[v[j]]);
                    return stoi(st);
                }
            }
        }
        return num;
    }
};