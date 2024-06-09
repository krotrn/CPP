#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout << "Enter the no. of string : ";
    int n;
    cin >> n;
    string v[n];
    cout << "Enter the string : " << endl;
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    string maxS = v[0];
    int m = stoi(v[0]), c=0;
    for (int i = 0; i < n;i++){
        int x = stoi(v[i]);
        if(x>m){
            m = x;
            c = i;
            maxS = v[i];
        }
    }
    cout << maxS <<" "<< m << " " << c;
}