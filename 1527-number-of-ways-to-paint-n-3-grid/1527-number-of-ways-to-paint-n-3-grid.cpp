class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> temp = {{0, 0, 0}, {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                {2, 3, 1}, {3, 1, 2}, {3, 2, 1}, {1, 2, 1},
                                {1, 3, 1}, {2, 1, 2}, {2, 3, 2}, {3, 1, 3},
                                {3, 2, 3}};
    int n;
    long long dp[5005][20];

    long long fixMod(long long a, long long b) {
        return (a % MOD + b % MOD) % MOD;
    }

    int valid(int i, int j) {
        for (int x = 0; x < 3; x++) {
            if (temp[i][x] == temp[j][x])
                return 0;
        }
        return 1;
    }

    long long solve(int i, int prv) {
        if (i == n)
            return 1;
        long long& ret = dp[i][prv];
        if (~ret)
            return ret;
        ret = 0;
        for (int j = 1; j < temp.size(); j++) {
            if (valid(prv, j))
                ret = fixMod(ret, solve(i + 1, j));
        }
        return ret;
    }

    int numOfWays(int nn) {
        memset(dp, -1, sizeof dp);
        n = nn;

        return solve(0, 0);
    }
};