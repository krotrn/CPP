#include <iostream>
#include <stack>
using namespace std;

string rmConsecDubli(string s)
{
    stack<char> st;
    string ans = "";
    ans += s[0];
    st.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != st.top())
        {
            ans += s[i];
            st.pop();
            st.push(s[i]);
        }
    }
    return ans;
}

int main()
{
    cout << "Enter the string : ";
    string s;
    cin >> s;
    for (char i : rmConsecDubli(s))
        cout << i << " ";
}