class Solution {
public:
    vector<vector<vector<int>>> dp;
    int kk, n, m;
    vector<vector<int>> g;
    int MOD = 1000000007;
    int fixMod(int val) { return val % MOD; }
    int solve(int i, int j, int mod) {
        if (i == n - 1 && j == m - 1) {
            return (g[i][j] + mod) % kk == 0;
        }
        if (i >= n || j >= m)
            return 0;

        int& ret = dp[i][j][mod];
        if (~ret)
            return ret;
        ret = 0;
        ret = fixMod(fixMod(solve(i + 1, j, (mod + g[i][j]) % kk)) +
                     fixMod(solve(i, j + 1, (mod + g[i][j]) % kk)));
        return ret;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        kk = k;
        g = grid;
        n = g.size();
        m = g[0].size();
        dp = vector<vector<vector<int>>>(
            n + 1, vector<vector<int>>(m + 1, vector<int>(55, -1)));

        return solve(0, 0, 0);
    }
};