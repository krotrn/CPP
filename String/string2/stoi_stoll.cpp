#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "Enter the string : ";
    string s;
    getline(cin, s);
    int x = stoi(s);
    cout << x << endl;
    long long y = stoll(s);
    cout << y << endl;
}