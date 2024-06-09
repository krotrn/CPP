#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrifix(vector<string>& strs){

    string x = "";

    if(strs.size() == 1) return strs[0];

    sort(strs.begin(), strs.end());

    for (int i = 0; i < strs[0][0]; i++){
        if(strs[0][i] == strs[(strs.size()-1)][i]){
            x += strs[0][i];
        }else{
            return x;
        }
    }
}

int main(){
    cout << "Enter the no. of string : ";
    int n;
    cin >> n;
    cout << "Enter the string : " << endl;
    vector<string> v;
    string s;
    for (int i = 0; i < n;i++){
        cin >> s;
        v.push_back(s);
    }
    s = longestCommonPrifix(v);

    cout << s << endl;
}