#include <iostream>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int solve(int b, int a, char c)
{
    if (c == '+')
    {
        return b + a;
    }
    else if (c == '-')
    {
        return b - a;
    }
    else if (c == '*')
    {
        return b * a;
    }
    else
        return b / a;
}

int infixEvaluation(string s)
{
    stack<int> st;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        // check if s[i] is an digit
        if (s[i] >= 48 && s[i] <= 57)
        { //
            st.push(s[i] - 48);
        }
        else
        { // s[i] is an operator
            if (op.size() == 0 || precedence(st.top()) < precedence(s[i]))
                op.push(s[i]);
            else
            {
                while (op.size() > 0 && precedence(op.top()) >= precedence(s[i]))
                {
                    char c = op.top();
                    op.pop();
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(solve(b, a, c));
                }
                op.push(s[i]);
            }
        }
    }
    while (op.size() > 0)
    {
        char c = op.top();
        op.pop();
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(solve(b, a, c));
    }
    return st.top();
}

int main()
{
    string s;
    cin >> s;
    cout << infixEvaluation(s) << endl;
    cout << 7 + 9 * 4 / 8 - 3 << endl;
}