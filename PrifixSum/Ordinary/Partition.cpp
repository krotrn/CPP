#include <all>
void Partition(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    for (int i = 1; i < n; i++)
    {
        if (2 * v[i] == v[n - 1])
        {
            cout << "Partition is vaild";
            return;
        }
    }
    cout << "Partition is Invaild";
    return;
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
    Partition(v);
}