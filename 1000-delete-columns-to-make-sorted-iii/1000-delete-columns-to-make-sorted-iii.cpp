class Solution {
public:
    int dp[105][106];
    int n, m;
    vector<string> s;

    int solve(int i, int prev) {
        if (i == m) return 0;

        int &ret = dp[i][prev];
        if (ret != -1) return ret;

        ret = solve(i + 1, prev) + 1; 
        bool ok = true;
        if (prev != m) {
            for (int r = 0; r < n; r++) {
                if (s[r][prev] > s[r][i]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            ret = min(ret, solve(i + 1, i));
        }

        return ret;
    }

    int minDeletionSize(vector<string>& strs) {
        s = strs;
        n = s.size();
        m = s[0].size();
        memset(dp, -1, sizeof dp);
        return solve(0, m);
    }
};
