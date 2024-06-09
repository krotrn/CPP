#include<iostream>
#include<vector>
using namespace std;
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

void display(vector<vector<int>> &v,int x,int y){
    for (int i = 0; i < x;i++){
        for (int j = 0; j < y; j++){
            cout << v[i][j] << " ";
        }
            cout << endl;
    }
}

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

    for (int i = 0; i < r;i++){
        if(v[i][0]==0){
            chr(v, i, c);
        }
    }

    for (int i = 0; i < c;i++){
        if(v[0][i]==0){
            chc(v, r, i);
        }
    }

    display(v, r, c);
}