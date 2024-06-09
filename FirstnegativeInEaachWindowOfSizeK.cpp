#include<all>
vector<int> FirstNegative(vector<int> &v, int k)
{
    int n = v.size();
    int p = -1;
    vector<int> a;
    for (int i = 0; i < k; i++)
    {
        if(v[i]<0)
        {
            p = i;
            break;
        }
    }
    if(p==-1)
        a[0] = 1;
    else
        a[0] = v[p];
    int i = 1;
    int j = k;
    while (j < n)
    {
        if(p>=i)
            a.push_back(v[p]);
        else
        {
            p = -1;
            for (int x = i; x < j; x++)
            {
                if(v[x]<0)
                {
                    p = x;
                    break;
                }
            }
            if(p!=-1)
                a.push_back(v[p]);
            else
                a.push_back(1);
        }
        i++;
        j++;
    }
    return a;
}
int main()
{
    cout << "Enter the no. Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Enter the K : ";
    int k;
    cin >> k;
    vector<int> a = FirstNegative(v, k);
    for(int e : a)
        cout << e << " ";
}