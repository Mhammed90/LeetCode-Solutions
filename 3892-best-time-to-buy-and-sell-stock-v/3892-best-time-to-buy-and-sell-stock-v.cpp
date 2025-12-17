class Solution {
public:
    long long dp[1005][505][3];
    int n;
    int prices[1005];

    long long solve(int i, int rem, int state) {
        if (rem < 0)
            return -1e15;
        if (i == n) {
            if (state == 0)
                return 0;
            return -1e15;
        }
        long long& ret = dp[i][rem][state];
        if (~ret)
            return ret;
        ret = solve(i + 1, rem, state);
        if (state == 0 && rem) {
            ret = max({ret, solve(i + 1, rem, 1) + prices[i],
                       solve(i + 1, rem, 2) - prices[i]});
        } else if (state == 1 && rem) {
            ret = max(ret, solve(i + 1, rem - 1, 0) - prices[i]);
        } else if (state == 2 && rem) {
            ret = max(ret, solve(i + 1, rem - 1, 0) + prices[i]);
        }
        return ret;
    }

    long long maximumProfit(vector<int>& p, int k) {
        n = p.size();
        for (int i = 0; i < n; i++)
            prices[i] = p[i];
        memset(dp, -1, sizeof dp);
        return solve(0, k, 0);
    }
};