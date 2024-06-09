#include<iostream>
#include<climits>
using namespace std;
int main(){
    cout << "Enter the no. of train : ";
    int n;
    cin >> n;
    float a[n];
    float b[n];
    for (int i = 0; i < n; i++){
        cout << "Arival of " << i + 1 << "th train : ";
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cout << "Enter it's Depature : ";
        cin >> b[i];
    }
    int sum = 1, max = INT_MIN;
    for (int i = 1, j = 0; i<n && j<n; ){
        if(a[i]<=b[j]){
            sum++;
            i++;
        }
        else{
            sum--;
            j++;
        }
        if(sum>max) max = sum;
    }
    cout << "Minimum " << max;
}