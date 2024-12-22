#include <bits/stdc++.h>
using namespace std;
void permutation(string &str, int idx, vector<string> &v){
    if(idx == str.size() - 1){
        v.push_back(str);
        return;
    }
    unordered_set<char> s;
    for (int i = idx; i < str.size(); i++){
        if(s.count(str[i]))
            continue;
        s.insert(str[i]);
        swap(str[i], str[idx]);
        permutation(str, idx + 1, v);
        swap(str[i], str[idx]);
    }
    return;
}
int main(){
    cout << "Enter the string: ";
    string str;
    cin >> str;
    vector<string> v;
    permutation(str, 0, v);
    for (auto i : v){
        cout << i << endl;
    }
    return 0;
}
