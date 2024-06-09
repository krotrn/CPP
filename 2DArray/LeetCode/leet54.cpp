#include<iostream>
using namespace std;
int main(){
    int m,n,i=0,j=0, c=0, r=0;
    cout<<"Enter the row and colomn of 1st matrix : "<<endl;
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter the of 1st matrix : "<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << endl;
    for (; c <= m && r <= n;)
    {
        // Right
        for (int j = c; j < n; j++)
        {
            cout << a[r][j] << " ";
        }
        if(c>n-1 || r>m-1) break;
        r++;
        // Down
        for (int i = r; i < m; i++){
            cout << a[i][n-1] << " ";
        }
        if(c>n-1 || r>m-1) break;
        n--;
        // Left
        for (int j = n-1; j >= c;j--){
            cout << a[m-1][j] << " ";
        }
        if(c>n-1 || r>m-1) break;
        m--;
        // Up
        for (int i = m-1; i >= r; i--){
            cout << a[i][c] << " ";
        }
        if(c>n-1 || r>m-1) break;
        c++;
    }
}