#include <bits/stdc++.h>
using namespace std;
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<int> v = satisfaction;
    for (int i = n - 2; i >= 0; i--)
    {
        v[i] += v[i + 1];
    }
    int idx = n;
    for (int i = 0; i < n; i++)
    {
        if(v[i]>=0) 
        {
            idx = i;
            break;
        }
    }
    int ans = 0;
    for (int i = idx; i < n; i++)
    {
        ans += ((i - idx + 1) * satisfaction[i]);
    }
    return ans;
}
int main()
{
    cout << "Enter the no. of Dishes : ";
    int n;
    cin >> n;
    cout << "Enter the Satisfaction Level of Dishes : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "The Max Satisfaction is : " << maxSatisfaction(v);
}