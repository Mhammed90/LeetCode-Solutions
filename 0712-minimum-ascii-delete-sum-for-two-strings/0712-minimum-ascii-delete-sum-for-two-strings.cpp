class Solution {
public:
    int dp[1005][1005];
    int suffx1[1005];
    int suffx2[1005];

    int solve(int i, int j, const string& s1, const string& s2) {
        if (i == s1.size()) {
            return suffx2[j];
        }
        if (j == s2.size()) {
            return suffx1[i];
        }

        int& ret = dp[i][j];
        if (~ret)
            return ret;
        ret = 1e9;
        int op1 = solve(i + 1, j, s1, s2) + ((int)s1[i]);
        int op2 = solve(i, j + 1, s1, s2) + ((int)s2[j]);
        int cost = (s1[i] == s2[j] ? 0 : ((int)s1[i] + (int)s2[j]));
        int op3 = solve(i + 1, j + 1, s1, s2) + cost;

        ret = min({op1, op2, op3});

        return ret;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        for (int i = n - 1; i >= 0; i--) {
            suffx1[i] = (int)s1[i] + suffx1[i + 1];
        }
        for (int i = m - 1; i >= 0; i--) {
            suffx2[i] = suffx2[i + 1] + (int)s2[i];
        }
        for (int i = 0; i <= n; i++)
            dp[i][m] = suffx1[i];

        for (int j = 0; j <= m; j++)
            dp[n][j] = suffx2[j];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int op1 = dp[i + 1][j] + (int)s1[i];
                int op2 = dp[i][j + 1] + (int)s2[j];
                int cost = (s1[i] == s2[j] ? 0 : (int)s1[i] + (int)s2[j]);
                int op3 = dp[i + 1][j + 1] + cost;

                dp[i][j] = min({op1, op2, op3});
            }
        }

        //  memset(dp, -1, sizeof(dp));
        return dp[0][0];
    }
};