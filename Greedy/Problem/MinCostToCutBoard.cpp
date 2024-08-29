#include <bits/stdc++.h>
using namespace std;

int minCost(int M, int N, vector<int> &X, vector<int> &Y){
     int hor = 1;
     int ver = 1;
     int cost = 0;
     sort(X.begin(), X.end(), [](int p1, int p2)
          { return p1 > p2; });
     sort(Y.begin(), Y.end(), [](int p1, int p2)
          { return p1 > p2; });
     int h = 0, v = 0;
     while (h < Y.size() && v < X.size()){
          if (X[v] > Y[h]){
               cost += X[v++] * ver;
               hor++;
          }else {
               cost += Y[h++] * hor;
               ver++;
          }
     }
     if (h == Y.size()){
          while (v < X.size())
               cost += X[v++] * ver;
     }else if (v == X.size()){
          while (h < Y.size())
               cost += Y[h++] * hor;
     }
     return cost;
}

int main(){
     int m = 6, n = 4;
     vector<int> X = {2, 1, 3, 1, 4}, Y = {4, 1, 2}; // Y = horizontal, X = vertical;
     cout << minCost(m, n, X, Y);
}