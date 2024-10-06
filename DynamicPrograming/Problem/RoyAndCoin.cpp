#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void royAndCoin(int n, vector<int> &L,vector<int> &R, int &q){
        // no. of coin per Box
        vector<int> v(n + 1);
        v[1] = L[1];
        int mx = v[1];
        // v[index] coin = box no. index
        for (int i = 2; i <= n; i++){
            v[i] = L[i] - R[i - 1] + v[i - 1];
            mx = max(mx, v[i]);
        }

        vector<int> c(mx + 1, 0);
        // c[index] boxes = (index) coin
        for (int i = 0; i <= n; i++){
            c[v[i]]++;
        }

        //  c[index] boxes = atleast (index) coin
        for (int i = mx - 1; i >= 0; i--){
            c[i] += c[i + 1];
        }

        while(q--){
            int num;
            cin >> num;
            if(num<=mx)
                cout << c[num] << endl;
            else
                cout << 0 << endl;
        }
        return;
    }
    void royAndCoin2(int n, vector<int> &v, int &q){
        for (int i = 1; i <= n; i++){
            v[i] += v[i - 1];
        }

        vector<int> c(n + 1, 0);
        for (int i = 0; i <= n; i++){
            c[v[i]]++;
        }

        for (int i = n - 1; i >= 0; i--){
            c[i] += c[i + 1];
        }

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
    vector<int> v(n + 1, 0), L(n + 1, 0), R(n + 1, 0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        L[l]++;
        R[r]++;
        v[l]++;
        v[r + 1]--;
    }
    int q;
    cin >> q;
    Solution s;
    s.royAndCoin2(n, v, q);
}