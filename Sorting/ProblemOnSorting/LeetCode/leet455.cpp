#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int c = g.size();
    int co = s.size();
    int count = 0;

    // sorting
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    for (int i = 0, j = 0; i < c && j < co; )
    {
        if(g[i] <= s[j])
        {
            count++;
            i++;
        }
        j++;
    }
    return count;
}

int main()
{
    cout << "Enter the no. of cookies : ";
    int c;
    cin >> c;
    cout << "Enter the sizes of cookies : " << endl;
    vector<int> s(c);
    for (int i = 0; i < c; i++)
    {
        cin >> s[i];
    }
    cout << "Enter the no. of children : ";
    int ch;
    cin >> ch;
    cout << "Enter the greed of children : " << endl;
    vector<int> g(ch);
    for (int i = 0; i < ch; i++)
    {
        cin >> g[i];
    }
    cout << findContentChildren(g, s);
}