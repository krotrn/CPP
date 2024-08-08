#include <bits/stdc++.h>
using namespace std;
void permutation(string ans, string og, vector<string> &v)
{
    if (og == "")
    {
        v.push_back(ans);
        return;
    }
    for (int i = 0; i < og.size();i++)
    {
        permutation(ans + og[i], og.substr(0,i)+og.substr(i+1) , v);
    }         
    return;
}

int main()
{
    cout << "Enter the string : ";
    string s;
    cin >> s;
    vector<string> v;
    permutation("", s, v);
    for (string ele : v)
    {
        cout << ele << endl;
    }
}