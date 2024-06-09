#include <all>

//  start with 1
int MissingNumber(vector<int> &v)
{
    int sum = 0;
    for (int e : v)
    {
        sum += e;
    }
    return ((v.size() * (v.size() + 1) / 2) - sum);
}

//  start with 1
int Cyclic(vector<int> &v)
{
    int n = v.size();
    int i = 0, correctIdx;
    while (i < n)
    {
        correctIdx = v[i];
        if (correctIdx == i || v[i] == n)
            i++;
        else
            swap(v[correctIdx], v[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i != v[i])
            return i;
    }

    return n;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << Cyclic(v);
}