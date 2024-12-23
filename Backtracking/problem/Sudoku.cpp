#include <bits/stdc++.h>

using namespace std;


class Solution{
    bool isSafe(vector<vector<int>> &grid, int row, int col, int val){
        // Row
        for (int i = 0; i < 9; i++){
            if(grid[i][col] == val || grid[row][i] == val)
                return false;
        }
        // Box
        int sr = row - row % 3, sc = col - col % 3;
        for (int i = sr; i < sr + 3; i++){
            for (int j = sc; j < sc + 3; j++){
                if(grid[i][j] == val)
                    return false;
            }
        }
        return true;
    }
    bool helping(vector<vector<int>> &grid, int row, int col){
        if(row == 9){
            for(auto r : grid){
                for(auto ele : r){
                    cout << ele << " ";
                }
                cout << endl;
            }
            return true;
        }
        if(col == 9)
            return helping(grid, row + 1, 0);
        

        if(grid[row][col] != 0)
            return helping(grid, row, col + 1);
        
        for (int i = 1; i <= 9; i++){
            if(isSafe(grid, row, col, i)){
                grid[row][col] = i;
                if(helping(grid, row, col + 1))
                    return true;
                grid[row][col] = 0;
            }
        }
        return false;
    }

public:
    void solveSuduko(vector<vector<int>> &grid){
        if(!helping(grid, 0, 0))
            cout << "No Solution Found" << endl;
        return;
    }
};


int main() {
    cout << "" << endl;
    return 0;
}