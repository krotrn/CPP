#include <bits/stdc++.h>
using namespace std;
bool Ispalindrome(string s,int i,int j)
{
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    else return Ispalindrome(s, i + 1, j - 1);
}

int main()
{
    cout << "Enter the string : ";
    string s;
    cin >> s;
    cout << Ispalindrome(s, 0, s.length()-1);
}