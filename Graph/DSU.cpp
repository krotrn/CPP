#include <bits/stdc++.h>

using namespace std;

// Function to find the root of an element x
// Uses path compression to flatten the structure
int find(vector<int> &parent, int x ) {
    return (parent[x] == x) ? x : parent[x] = find(parent, parent[x]);
}

// Function to perform union of two sets
// Uses union by rank to keep the tree shallow
void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a); // Find the root of element a
    b = find(parent, b); // Find the root of element b
   if (a != b) { // Only union if roots are different
        // Union by rank
        if (rank[a] > rank[b]) {
            parent[b] = a; // Make a the parent of b
        } else if (rank[a] < rank[b]) {
            parent[a] = b; // Make b the parent of a
        } else {
            parent[b] = a; // Arbitrarily choose one as root
            rank[a]++;     // Increment rank of the new root
        }
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