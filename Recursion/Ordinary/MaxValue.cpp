#include <bits/stdc++.h>
using namespace std;
void Max(vector<int>& v, int m, int n)
{
    if (n == v.size())
    {
        cout << m;
        return;
    }
    if (v[n] > m) m = v[n];
    Max(v, m, n + 1);
    return;
}
int maxPr(vector<int>& v, int n)
{
    if (n == v.size()) return INT_MIN;
    return max(v[n], maxPr(v, n + 1));
}
int main()
{
    cout << "Enter the no. of element : ";
    int n;
    cin >> n;
    cout << "Enter the elements : " << endl;
    vector<int> v(n);
    for (int i = 0;i < n;i++)
    {
        cin >> v[i];
    }
    // Max(v, INT_MIN, 0);
    cout << maxPr(v, 0);

}