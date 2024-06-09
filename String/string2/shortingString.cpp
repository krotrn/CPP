#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout << "enter the string : ";
    string s;
    getline(cin, s);
    sort(s.begin(), s.end());
    cout << s;
}