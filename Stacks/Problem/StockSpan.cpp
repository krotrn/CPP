#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> span(vector<int> &v)
{
    stack<int> st;
    int n = v.size();
    vector<int> ans(n);
    ans[0] = 1;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (st.size() && v[st.top()] <= v[i])
            st.pop();
        if (st.size() != 0)
            ans[i] = i - st.top();
        else
            ans[i] = 1;

        st.push(i);
    }
    return ans;
}

int main()
{
    cout << "Enter the no. of Element : ";
    int n;
    cin >> n;
    cout << "Enter the Element : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans;
    for (int e : span(v))
        cout << e << " ";
}