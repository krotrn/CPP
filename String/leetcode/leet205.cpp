#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isIsomorphic(string s,string t){
    if(s.size() != t.size()) return false;
    vector<int> v(150, 1000);
    for (int i = 0; i < s.length(); i++){
        if(v[(int)s[i]] == 1000){
            v[(int)s[i]] = s[i] - t[i];
        }
        else{
            if( v[(int)s[i]] != s[i] - t[i]){
                return false;
            }
            else{
                continue;
            }
        }
    }
    for (int i = 0; i < t.length(); i++){
        if(v[(int)t[i]] == 1000){
            v[(int)t[i]] = s[i] - t[i];
        }
        else{
            if( v[(int)t[i]] != s[i] - t[i]){
                return false;
            }
            else{
                continue;
            }
        }
    }
    return true;
}

int main(){
    cout << "Enter the strings : ";
    string s, t;
    cin >> s >> t;
    bool p = isIsomorphic(s, t);
    cout << p;

}