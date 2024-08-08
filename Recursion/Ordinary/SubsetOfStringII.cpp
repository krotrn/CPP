#include <bits/stdc++.h>
using namespace std;
void storesubstr(string ans, string og, vector<string> &v,bool t)
{
    if (og == "")
    {
        v.push_back(ans);
        return;
    }
    if (t) //   not add
    {
        storesubstr(ans + og[0], og.substr(1), v,true);
    }
    if (og.size() != 1 && og[0] == og[1] )   //  recorgnizing dublicate
    {
        storesubstr(ans, og.substr(1), v,false);
    }else
    {
        storesubstr(ans, og.substr(1), v,true);
    }
    return;
}

int main()
{
    cout << "Enter the string : ";
    string s;
    cin >> s;
    vector<string> v;
    storesubstr("", s, v,true);
    for (string ele : v)
    {
        cout << ele << endl;
    }
}