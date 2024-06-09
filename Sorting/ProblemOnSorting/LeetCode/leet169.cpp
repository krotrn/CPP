#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MajorityElements(vector<int> &nums){
    sort(nums.begin(), nums.end());
    return nums[(nums.size() / 2)];
}

int main (){
    cout << "Enter the no. of Elements : ";
    int n;
    cin >> n;
    cout << "Enter the Elements : " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << "The Majority of Elements is : " << MajorityElements(v);
}