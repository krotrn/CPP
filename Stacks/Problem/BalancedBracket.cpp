#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s)
{
    int opening = 0;
    int closing = 0;
    for (int i : s)
    {
        if (i == '(')
            opening++;
        else
            closing++;
        if (opening < closing)
            return false;
    }
    return true;
}
bool isBalancedStack(string s)
{
    stack<char> st;
    for (char i : s)
    {
        if (i == '(')
            st.push(i);
        else
        {
            if (st.size() == 0)
                return false;
            else if (st.top() == '(')
                st.pop();
        }
    }
    if (st.size() == 0)
        return true;
    else
        return false;
}

int main()
{
    cout << "Enter the String : ";
    string s;
    cin >> s;
    cout << "The Brackets are Balanced : ";
    (isBalancedStack(s)) ? cout << "Yes" : cout << "No";
}