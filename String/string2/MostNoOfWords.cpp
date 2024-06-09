#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    cout << "Enter the string : ";
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> v;
    string t;

    while(ss>>t){
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int c = 1, m = 0;
    for (int i = 1; i < v.size(); i++){
        if (v[i] == v[i - 1]){
            c++;
        }
        else {
            c = 1;
        }
        m = max(m, c);
    }

    c = 1;
    for (int i = 1; i < v.size(); i++){
        if (v[i] == v[i - 1]){
            c++;
        }
        else{
            c = 1;
        }
        if (c == m){
            cout << v[i] << " " << m << endl;
        }
    }
}