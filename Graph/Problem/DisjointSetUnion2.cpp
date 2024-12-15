#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/
// IMO Academy: pilot>>Disjoint>>Step 1>>practice>>B


int find(vector<int> &parent, int x ) {
    return (parent[x] == x) ? x : parent[x] = find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &sz, vector<int> &minimal, vector<int> &maximal, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b); 
   if (a != b) { 
        if (rank[a] > rank[b]) {
            parent[b] = a;
            sz[a] += sz[b];
            maximal[a] = max(maximal[a], maximal[b]);
            minimal[a] = min(minimal[a], minimal[b]);
        } else if (rank[a] < rank[b]) {
            parent[a] = b;
            sz[b] += sz[a];
            maximal[b] = max(maximal[a], maximal[b]);
            minimal[b] = min(minimal[a], minimal[b]);
        } else {
            parent[b] = a;
            sz[a] += sz[b];
            maximal[a] = max(maximal[a], maximal[b]);
            minimal[a] = min(minimal[a], minimal[b]);
            rank[a]++;
        }
    }
}

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main(){
    speedup();
    int n;
    cin >> n;
    vector<int> parent(n + 1), rank(n + 1, 1), sz(n + 1, 1), minimal(n + 1), maximal(n + 1);
    int q;
    cin >> q;
    for (int i = 0; i <= n; i++)
        parent[i] = minimal[i] = maximal[i] = i;
    string s;
    while(q--){
        cin >> s;
        if(s == "union"){
            int x, y;
            cin >> x >> y;
            Union(parent, sz, minimal, maximal, rank, x, y);
        }else {
            int x;
            cin >> x;
            x = find(parent, x);
            cout << minimal[x] << " " << maximal[x] << " " << sz[x] << endl;
        }
    }
    return 0;
}