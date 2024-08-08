#include <bits/stdc++.h>
using namespace std;
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int n = customers.size();
    int prevloss = 0;
    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 1)
            prevloss += customers[i];
    }
    int i = 0;
    int j = minutes;
    int maxloss = prevloss;
    int maxidx = 0;
    while(j<n)
    {
        int currloss = prevloss;
        currloss += ((grumpy[j] * customers[j]) - (grumpy[i - 1] * customers[i - 1]));
        if(maxloss<currloss)
        {
            maxloss = currloss;
            maxidx = i;
        }
        prevloss = currloss;
        i++;
        j++;
    }
    for (int i = maxidx; i < (maxidx + minutes); i++)
    {
        grumpy[i] = 0;
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (grumpy[i] == 0)
            max += customers[i];
    }
    return max;
}

int main()
{
    cout << "Enter the no. of Minutes : ";
    int n;
    cin >> n;
    cout << "Enter the no. of Customer in that Minutes : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Enter the minutes where Shopkeeper hold his Grumpyness : ";
    int m;
    cin >> m;
    cout << "Enter the time Where Owner is Grumpy : " << endl;
    vector<int> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    cout << "The Max Satisfied Costomer is : " << maxSatisfied(v, g, m);
}