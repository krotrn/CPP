#include<all>

int Maxsum(vector<int>& v, int k)
{
    int n = v.size();
    int maxS = 0;
    for (int i = 0; i < k; i++)
        maxS += v[i];
    int i = 0, j = k;
    while(j<n)
        maxS = max(maxS, maxS + v[j++] - v[i++]);
    return maxS;
}

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Enter the K : ";
    int k;
    cin >> k;
    cout << Maxsum(v,k);
}