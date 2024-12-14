#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &parent, int x ) {
    return (parent[x] == x) ? x : parent[x] = find(parent, parent[x]);
}

void Union(vector<int> &parent,vector<int> &rank, int a, int b){
    a = find(parent, a);
    b = find(parent, b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }else{
        rank[b]++;
        parent[a] = b;
    }
}

int main(){
    int n;
    cout << "Enter the No. of Elements : ";
    cin >> n;
    vector<int> parent(n + 1), rank(n + 1, 1);
    int q;
    cout << "Enter the no. of Query : ";
    cin >> q;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int x, y;
    char s;
    while(q--){
        cout << "Enter the numbers and operations : " << endl;
        cin >> x >> y >> s;
        if(s=='u')
            Union(parent, rank, x, y);
        else {
            cout << "Parent of " << x << " is : " << find(parent, x) << endl;
            cout << "Parent of " << y << " is : " << find(parent, y) << endl;
        }
    }
    return 0;
}