#include <bits/stdc++.h>
using namespace std;
void bswc1(string ans, int n, vector<string>& v)
{
    if(n==0)
    {
        v.push_back(ans);
        return;
    }
    bswc1(ans + '0', n-1, v);
    if (ans=="" || ans[ans.length() - 1] == '0') bswc1(ans + '1', n-1, v);
    return;
}
int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    vector<string> v;
    bswc1("", n, v);
    for (string e : v)
    {
        cout << e << endl;
    }
}