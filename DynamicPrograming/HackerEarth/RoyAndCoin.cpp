#include <bits/stdc++.h>
using namespace std;

// https://www.hackerearth.com/problem/algorithm/roy-and-coins-f386330e/

class Solution{
public:
    void royAndCoin(int n, vector<int> &L,vector<int> &R, int &q){
        // creating with query effect
        vector<int> f(n + 1);

        // first box only have those effect which are starts from 1
        f[1] = L[1];

        // finding maximum effect
        int mx = f[1];


        // no. of effect = coins
        // f[i] no. of coins in ith box
        for (int i = 2; i <= n; i++){ // O(n)

            // effect at ith box have coin = (effect starting  from ith box (L[i])) + (effect starting from i - 1th box) + (effect starting from i - 2th box) ....
            // - (effect end at i - 1th box) - {effect end at i - 2th box} - (effect end at i - 3th box) ......
            // converted into => (effect starting from ith box) + (effect calculated till i - 1) - (effect end at i - 1th box)
            f[i] = L[i] - R[i - 1] + f[i - 1];

            // for calculartion of maximum effect
            mx = max(mx, f[i]);
        }


        // max is for it will not exceed max
        vector<int> c(mx + 1, 0); // O(n)
            // for calculation of c[i] no. of boxes with i coins
        for (int i = 0; i <= n; i++)
            c[f[i]]++;
        

            // for calculation of c[i] no.of boxes with atleast i coins by suffix sum
        for (int i = mx - 1; i >= 0; i--) // O(mx)
            c[i] += c[i + 1];
        

        while(q--){ // O(q)
            int num;
            cin >> num;
            if(num<=mx)
                cout << c[num] << endl;
            else
                cout << 0 << endl;
        }
        return;
    }


    void royAndCoin2(int n, vector<int> &f, int &q){
        
        // finding maximum effect
        int mx = f[1];

        // by prefix sum we can calculate effect per box == no. of coins per box
        for (int i = 1; i <= n; i++){ // O(n)
            f[i] += f[i - 1];
            // for calculartion of maximum effect
            mx = max(mx, f[i]);
        }

        vector<int> c(mx + 1, 0);
             // for calculation of c[i] no. of boxes with i coins
        for (int i = 0; i <= n; i++)// O(n)
            c[f[i]]++;
        

            // for calculation of c[i] no. of boxes with atleast i coins by suffix sum
        for (int i = mx - 1; i >= 0; i--) // 
            c[i] += c[i + 1];
        

        while(q--){
            int num;
            cin >> num;
            if(num<=n)
                cout << c[num] << endl;
            else
                cout << 0 << endl;
        }
        return;
    }
};

int main(){
    int n;
    cin >> n;
    // for methord 1
    // for collecting starting and ending filling
    // vector<int> L(n + 1, 0), R(n + 1, 0); 
    vector<int> f(n + 1, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){ // O(m)
        int l, r;
        cin >> l >> r;
        // starting filling at l
        // L[l]++;
        // ending filling at r
        // R[r]++;

        // start effecting
        f[l]++;
        // nullifying effecting
        f[r + 1]--;
    }
    int q;
    cin >> q;
    Solution s;
    s.royAndCoin2(n, f, q);
    // s.royAndCoin(n, L, R, q);
}