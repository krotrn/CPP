#include<iostream>
#include<vector>
using namespace std;
// int f(int x){
//     int a=1;
//     for (int i = 1 ; i <= x; i++){
//         a *= i;
//     }
//     return a;
// }
// int c(int x,int y){
//     int a = (f(x)) / (f(x - y) * f(y));
//     return a;
// }
int main(){
    cout << "Enter ending elements : ";
    int n;
    cin >> n;
    vector<vector<int>> v;
    
    for (int i = 0; i < n;i++){
        vector<int> a(i+1);
        v.push_back(a);
        for (int j = 0; j <= i;j++){
            if(j==0 || j==i) {
                v[i][j] = 1;
            }
            else{
                v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= i;j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}