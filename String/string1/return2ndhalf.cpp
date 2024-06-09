#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout << "Enter the string : ";
    string s;
    getline(cin, s);
    cout << s.substr(s.size()/2);
}