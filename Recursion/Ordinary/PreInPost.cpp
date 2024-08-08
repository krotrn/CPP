#include <bits/stdc++.h>
using namespace std;
void PreInPost(int n)
{
    if (n == 0) return;
    cout << "Pre - " << n << endl;
    PreInPost(n - 1);
    cout << "In - " << n << endl;
    PreInPost(n - 1);
    cout << "Post - " << n << endl;
}
int main()
{
    int n;
    cin >> n;
    PreInPost(n);
}