class Solution {
public:
    bool isMagic( vector<vector<int>>& g, int r, int c) {
        // Check numbers 1..9 exactly once
        vector<bool> seen(10, false);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int x = g[r + i][c + j];
                if (x < 1 || x > 9 || seen[x])
                    return false;
                seen[x] = true;
            }
        }

        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2] != 15)
                return false;
            if (g[r][c + i] + g[r + 1][c + i] + g[r + 2][c + i] != 15)
                return false;
        }

        // Check diagonals
        if (g[r][c] + g[r + 1][c + 1] + g[r + 2][c + 2] != 15)
            return false;
        if (g[r][c + 2] + g[r + 1][c + 1] + g[r + 2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (isMagic(grid, i, j))
                    cnt++;
            }
        }
        return cnt;
    }
};