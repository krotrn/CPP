#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
    cout << "Enter the string : ";
    string s;
    getline(cin, s);
    stringstream ss(s);
    string temp;

    while (ss >> temp){
        cout << temp << endl;
    }
}