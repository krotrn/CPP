#include<iostream>
#include<algorithm>
using namespace std;
int main (){
    cout << "Enter a word greater than 5 : ";
    string s;
    getline(cin, s);
    reverse(s.begin() + 1, s.begin() + 5);
    cout << s << endl;
}