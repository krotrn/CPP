#include<iostream>
using namespace std;
int main(){
    // string str = "karan kumar sah";
    // cout << str << str.size();
    string s;
    // cin >> s; //no input with space
    getline(cin, s); // get full line
    cout << s;
}