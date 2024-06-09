#include<iostream>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    // cout << "Enter the position you want to change : ";
    // int n;
    // cin >> n;
    
    s[5] = 'c';
    cout << s;
}