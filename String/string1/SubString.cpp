#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cout << "Enter the string : ";
    getline(cin, s);
    // s.substr(intex, length);
    cout << s.substr(1,3);
}