class Solution {
public:
    int M, N;
    int dp[601][101][101];
    vector<pair<int, int>> p;
    int solve(int i, int o, int z) {
        if (z > M || o > N)
            return -100000;
        if (i == p.size()) {
            return 0;
        }
        int& ret = dp[i][o][z];
        if (~ret)
            return ret;

        ret = 0;
        ret = max({ret, solve(i + 1, o + p[i].second, z + p[i].first) + 1,
                   solve(i + 1, o, z)});
        return ret;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        M = m, N = n;
        memset(dp, -1, sizeof(dp));
        for (auto& i : strs) {
            int c = count(i.begin(), i.end(), '0');
            p.push_back({c, i.size() - c});
        }
        int ans = solve(0, 0, 0);

        return ans;
    }
};