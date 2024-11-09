#include<iostream>
#include<vector>
using namespace std;
class Solution {
    void chr(vector<vector<int>> &v,int x,int y){
        for (int i = 0; i < y; i++){
            if(v[x][i]==0) v[x][i] = 1;
            else v[x][i] = 0;
        }
    }

    void chc(vector<vector<int>> &v,int x,int y){
        for (int i = 0; i < x; i++){
            if(v[i][y]==0) v[i][y] = 1;
            else v[i][y] = 0;
        }
    }
    int sum(vector<vector<int>> &v,int r,int c){
        int sum = 0;
        for (int i = 0; i<r; i++){
            int x = 1;
            for(int j = c-1; j>=0; j--){
                sum += v[i][j]*x;
                x *= 2;
            }
        }
        return sum;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r;i++){
            if(grid[i][0]==0){
                chr(grid, i, c);
            }
        }

        for(int j=0; j<c; j++){
            int noz=0,noo=0;
            for(int i=0; i<r; i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
            if(noz>noo){
                chc(grid, r, j);
            }
        }

        return sum(grid,r,c);
    }
};

int main(){
    cout << "Enter rows and coloumn : ";
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> v[i][j];
        }
    }

    Solution s;
    cout << s.matrixScore(v) << endl;

    display(v, r, c);
}