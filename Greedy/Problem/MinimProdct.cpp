#include<bits/stdc++.h>
using namespace std;

int minProdct(vector<int> &v){
    int n = v.size();
    sort(v.begin(), v.end());
    if (v[0] >= 0)
        return v[0];
    int count = 0;
    int product = 1;
    for (int i = 0; i < n; i++){
        if(!v[i])
            continue;
        else if (v[i] < 0)
            count++;
        if ((v[i] < 0 && i == n - 1 && count % 2) || (v[i] < 0 && v[i + 1] >= 0 && count % 2))
            continue;
        product *= v[i];
    }
    return product;
}

int main(){
    vector<int> v = {1, -1, 3, -6, 2};
    cout << minProdct(v);
}