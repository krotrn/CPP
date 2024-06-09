#include<iostream>
#include<vector>
#include<pow>
using namespace std;
void change(int a[][3]){
    a[0][0]=9;
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << pow(a, b);
}