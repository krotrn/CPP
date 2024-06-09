#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    vector<int> c;
    vector<int> d;
    cout << "Enter no. of element in First array : ";
    cin >> m;
    int a[m];
    cout << "Enter the elements of First array : " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << "Enter no. of element in second array : ";
    cin >> n;
    int b[n];
    cout << "Enter elements of array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0, j = 0; i < m, j < n;)
    {
        if (a[i] <= b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    cout << "Union of these array is : " << endl;
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    for (int i = 0, j = 0; i < n, j < m;)
    {
        if (a[i] == b[j])
        {
            d.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else if (b[j] < a[i])
            j++;
    }
    cout << "Intersection of these array is : " << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
}