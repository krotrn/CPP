#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    // reverse first half
    reverse(s.begin(), s.begin() + (s.size() / 2) );
    cout << s << endl;
}