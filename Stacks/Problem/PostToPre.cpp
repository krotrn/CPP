#include <iostream>
#include <stack>
#include <string>
using namespace std;

string solve(string val1, string val2, char op)
{
    return op + val1 + val2;
}   

string postfixToInfixEvaluation(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(to_string(s[i] - '0'));
        }
        else
        {
            string val2 = st.top();
            st.pop();
            string val1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(solve(val1, val2, '+'));
                break;
            case '-':
                st.push(solve(val1, val2, '-'));
                break;
            case '*':
                st.push(solve(val1, val2, '*'));
                break;
            case '/':
                st.push(solve(val1, val2, '/'));
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s = "79+4*8/3-";
    cout << postfixToInfixEvaluation(s) << endl;
}