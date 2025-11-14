class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 2, vector<int>(n + 2));
        for (auto i : queries) {
            int x1 = i[0], y1 = i[1], x2 = i[2], y2 = i[3];
            diff[x1][y1] += 1;
            diff[x1][y2 + 1] -= 1;
            diff[x2 + 1][y1] -= 1;
            diff[x2 + 1][y2 + 1] += 1;
        }
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = (i > 0 ? grid[i - 1][j] : 0);
                int left = (j > 0 ? grid[i][j - 1] : 0);
                int diag = (i > 0 && j > 0 ? grid[i - 1][j - 1] : 0);

                grid[i][j] = diff[i][j] + up + left - diag;
            }
        }
        return grid;
    }
};