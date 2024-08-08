#include <bits/stdc++.h>
using namespace std;
string helper(string ans, string str, int k)
{
    int n = str.length();
    if (n == 1)
    {
        ans += str;
        return ans;
    }
    int p = 1;
    for (int i = 2; i < n; i++)
    {
        p *= i;
    }
    int idx = k / p;
    if (k % p == 0)
    {
        idx--;
    }
    if (k % p == 0)
    {
        k = p;
    }
    else if (k > p)
    {
        k = k % p;
    }
    return helper(ans + str[idx], str.substr(0, idx) + str.substr(idx + 1), k);
}

string getPermutation(int n, int k)
{
    string str = "";
    for (int i = 1; i <= n; i++)
    {
        str += to_string(i);
    }
    string s = "";
    return helper(s, str, k);
}

int main()
{
    cout << "Enter the N : ";
    int n;
    cin >> n;
    cout << "Enter the k : ";
    int k;
    cin >> k;
    cout << getPermutation(n, k);
}