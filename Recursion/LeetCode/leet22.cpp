#include <bits/stdc++.h>
using namespace std;
void gen(string ans, vector<string> &v, int o, int c)
{
    if (ans[0] == ')')
        return;
    if (c == 0 && o == 0)
    {
        v.push_back(ans);
        return;
    }
    else if(c<0 || o<0)
        return;
    if (o <= c)
    {
        gen(ans + '(', v, o - 1, c);
        gen(ans + ')', v, o, c - 1);
    }
    return;
}

vector<string> generateParenthesis(int n)
{
    vector<string> v;
    gen("", v,n,n);
    return v;
}

int main()
{
    cout << "Enter no. of Pair : ";
    int n;
    cin >> n;
    vector<string> v = generateParenthesis(n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}