#include<iostream>
using namespace std;
int main(){
    cout<<"Enter The No. Of Character : ";
    int n;
    cin >> n;
    char c[n];
    int count = 0;
    for (int i = 0; i < n; i++){
        cin >> c[i];
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u'){
            count++;
        }
    }
    cout << count;
}