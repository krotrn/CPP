#include <bits/stdc++.h>
using namespace std;
void storesubstr(string ans,string og,vector<string>& v)
{
    if(og=="")
    {
        v.push_back(ans);
        return;
    }
    storesubstr(ans + og[0], og.substr(1),v);   //  add and cut then run
    storesubstr(ans, og.substr(1),v);           //  cut then run
    return;
}

int main()
{
    cout << "Enter the string : ";
    string s;
    cin >> s;
    vector<string> v;
    storesubstr("", s,v);
    for(string ele : v)
    {
        cout << ele << endl;
    }
}