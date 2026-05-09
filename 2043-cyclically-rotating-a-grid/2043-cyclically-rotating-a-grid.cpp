class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int T = 0, L = 0;
        int B = grid.size() - 1;
        int R = grid[0].size() - 1;

        while (T < B && L < R) {

            vector<pair<int,int>> points;
            vector<int> vals;

            for (int j = L; j < R; j++) {
                points.push_back({T, j});
                vals.push_back(grid[T][j]);
            }

            for (int i = T; i < B; i++) {
                points.push_back({i, R});
                vals.push_back(grid[i][R]);
            }

            for (int j = R; j > L; j--) {
                points.push_back({B, j});
                vals.push_back(grid[B][j]);
            }

            for (int i = B; i > T; i--) {
                points.push_back({i, L});
                vals.push_back(grid[i][L]);
            }

            int sz = vals.size();
            int r = k % sz;

            rotate(vals.begin(), vals.begin() + r, vals.end());

            for (int i = 0; i < sz; i++) {
                auto [x, y] = points[i];
                grid[x][y] = vals[i];
            }

            T++;
            L++;
            B--;
            R--;
        }

        return grid;
    }
};