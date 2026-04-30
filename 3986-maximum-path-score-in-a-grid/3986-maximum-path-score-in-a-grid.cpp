class Solution {
public:
    int n, m;

    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int rem, vector<vector<int>>& grid) {
        if (i == n || j == m || rem < 0)
            return -1e9;
        if (i == n - 1 && j == m - 1) {
            int dec = grid[i][j] != 0;
            if (rem - dec < 0)
                return -1e9;
            return grid[i][j];
        }

        int& ret = dp[i][j][rem];
        if (~ret)
            return ret;
        ret = -1e9;

        ret = max(
            {ret, solve(i + 1, j, rem - (grid[i][j] != 0), grid) + grid[i][j],
             solve(i, j + 1, rem - (grid[i][j] != 0), grid) + grid[i][j]});

        return ret;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        dp.resize(n + 5, vector<vector<int>>(
                             m + 5, vector<int>(min(k + 5, m + n + 5), -1)));

        return max(-1, solve(0, 0, min(n + m + 1, k), grid));
    }
};
