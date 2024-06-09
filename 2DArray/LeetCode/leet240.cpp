#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0, j = n - 1; i < m && j <= 0;){
        if (matrix[i][j] == target){
            return true;
        }
        else if (matrix[i][j] > target){
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}
int main (){
    cout << "Enter rows and coloumn : ";
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    cout << "Enter the target element : ";
    int x;
    cin >> x;

    searchMatrix(v, x);
}