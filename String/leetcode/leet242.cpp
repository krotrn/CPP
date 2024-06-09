#include <iostream>
#include <string>
#include <algorithm>
// combination(s) = t;
using namespace std;
int main()
{
    cout << "enter first string : ";
    string s;
    getline(cin, s);
    cout << "enter Second string : ";
    string t;
    getline(cin, t);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (t == s)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}