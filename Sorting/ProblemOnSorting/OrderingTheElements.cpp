#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n), a(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // int m = INT_MAX, c = 0, t = 0;
    // for (int i = 0; i < n; i++){
    //     // Finding smallest element
    //     if (a[i] == 1){ continue; }
    //     if (v[i] <= m )
    //     {
    //         m = v[i];
    //         c = i;
    //     }

    //     if (i == n - 1){

    //         v[c] = t;
    //         a[c] = 1;
    //         if(t==n-1){
    //             break;
    //         }
    //         i = -1;
    //         t++;
    //         m = INT_MAX;
    //     }
    // }
    int x = 0;
    // for (int i = 0; i < n; i++){
    //     int m = INT_MAX, c = -1;
    //     for (int j = 0; j < n; j++){
    //         if (a[j] == 1){ continue; }
    //         else{
    //             if (v[j] < m ){
    //             m = v[j];
    //             c = j;
    //             }
    //         }
    //     }
    //     v[c] = i;
    //     a[c] = 1;
    // }

    for (int i = 0; i < n; i++)
    {
        int m = INT_MAX, c = -1;
        for (int j = 0; j < n; j++)
        {
            if (v[j] <= 0)
            {
                continue;
            }
            else
            {
                if (v[j] < m)
                {
                    m = v[j];
                    c = j;
                }
            }
        }
        v[c] = -i;
    }

    for (int e : v)
    {
        e = -e;
        cout << e << " ";
    }
}