#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    string v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'X')
        {
            v.push_back(s[i]);
        }
    }
    bool flag = true;
    for (int i = 0; i < v.size() - 1; i++)
    {
        flag = true;
        // Transverse Sort
        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] < v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
    cout << v;
}