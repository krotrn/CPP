#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout << "Enter the digit : ";
    int n;
    cin >> n;
    string s = to_string(n);
    cout << s.size();
}