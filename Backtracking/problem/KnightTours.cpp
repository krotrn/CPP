#include <bits/stdc++.h>

using namespace std;

class Solution {
    void helper(vector<vector<int>>& v, int row, int col, int count) {
        if (count == v.size() * v.size()) {
            for (auto r : v) {
                for (auto ele : r) {
                    cout << ele << " ";
                }
                cout << endl;
            }
            cout << "*** *** *** *** ***" << endl;
            return;
        }

        vector<pair<int, int>> direction = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto d : direction) {
            if (row + d.first >= 0 && row + d.first < v.size() && col + d.second >= 0 && col + d.second < v.size() && v[row + d.first][col + d.second] == 0) {
                v[row][col] = count;
                helper(v, row + d.first, col + d.second, count + 1);
                v[row][col] = 0;
            }
        }
        return;
    }
public:
    void knightTour(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));

        helper(v, 0, 0, 1);
    }
};

int main() {
    Solution sol;
    int n = 5; // Size of the chessboard
    sol.knightTour(n);
    return 0;
}