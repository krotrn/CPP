#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReachEnd(vector<vector<char>> grid) {
        int r = grid.size();
        int c = grid[0].size();
        int step = 0;
        int i = 0, j = 0;
        while (step < r * c){
            if(i<0 || i == r || j<0 || j==c)
                return false;
            if(i == r - 1 && j == c - 1)
                return true;
            switch (grid[i][j]) {
                case 'R': j++; break;
                case 'L': j--; break;
                case 'D': i++; break;
                case 'U': i--; break;
            }
            step++;
        }
        return false;
    }
};

class Solution {
public:
    bool canReachEnd(vector<vector<char>> &grid) {
        int r = grid.size();
        int c = grid[0].size();

        // Encode the starting position
        int slow = 0, fast = 0;

        while (true) {
            // Move slow pointer one step
            slow = nextPosition(grid, slow, r, c);
            if (slow == -1) return false; // Out of bounds
            if (slow == r * c - 1) return true; // Reached bottom-right corner

            // Move fast pointer two steps
            fast = nextPosition(grid, fast, r, c);
            if (fast == -1) return false; // Out of bounds
            if (fast == r * c - 1) return true; // Reached bottom-right corner

            fast = nextPosition(grid, fast, r, c);
            if (fast == -1) return false; // Out of bounds
            if (fast == r * c - 1) return true; // Reached bottom-right corner

            // Cycle detected
            if (slow == fast) return false;
        }
    }

private:
    int nextPosition(const vector<vector<char>> &grid, int pos, int r, int c) {
        int i = pos / c;
        int j = pos % c;

        switch (grid[i][j]) {
            case 'R': j++; break;
            case 'L': j--; break;
            case 'D': i++; break;
            case 'U': i--; break;
        }

        // Check bounds
        if (i < 0 || i >= r || j < 0 || j >= c) return -1;

        // Encode the new position
        return i * c + j;
    }
};
