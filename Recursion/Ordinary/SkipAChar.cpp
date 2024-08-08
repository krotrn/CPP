#include <bits/stdc++.h>
using namespace std;
void skip(string str, string ans, char x, int i)
{
    if (i == str.size())
    {
        cout << ans;
        return;
    }
    if (str[i] != x) ans += str[i];
    skip(str.substr(1), ans, x, i+1);
}
int main()
{
    cout << "Enter the string : " << endl;
    string s;
    getline(cin, s);
    cout << "Enter the character that will skip : ";
    char x;
    cin >> x;
    skip(s, "", x, 0);
}