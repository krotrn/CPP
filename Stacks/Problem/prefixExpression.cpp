#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int precedence(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
}

string solve(string a, string b, char c)
{
    string res = "";
    res.push_back(c);
    res += b;
    res += a;
    return res;
}

string InfixToPrefix(string s)
{
    stack<string> st;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        { //
            st.push(to_string(s[i] - 48));
        }
        else
        {
            if (op.empty() || s[i] == '(' || op.top() == '(')
            {
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (op.top() != '(')
                {
                    char c = op.top();
                    op.pop();
                    string a = st.top();
                    st.pop();
                    string b = st.top();
                    st.pop();
                    st.push(solve(a, b, c));
                }
                op.pop();
            }
            else if (precedence(s[i]) > precedence(op.top()))
            {
                op.push(s[i]);
            }
            else
            {
                while (!op.empty() && precedence(op.top()) >= precedence(s[i]))
                {
                    char c = op.top();
                    op.pop();
                    string a = st.top();
                    st.pop();
                    string b = st.top();
                    st.pop();
                    st.push(solve(a, b, c));
                }
                op.push(s[i]);
            }
        }
    }
    while (!op.empty())
    {
        char c = op.top();
        op.pop();
        string a = st.top();
        st.pop();
        string b = st.top();
        st.pop();
        st.push(solve(a, b, c));
    }
    return st.top();
}

int main()
{
    string s;
    cin >> s;
    cout << InfixToPrefix(s) << endl;
}