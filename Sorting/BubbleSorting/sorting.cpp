#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cout << "enter the size : ";
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end()); // O(nlogn)
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

}