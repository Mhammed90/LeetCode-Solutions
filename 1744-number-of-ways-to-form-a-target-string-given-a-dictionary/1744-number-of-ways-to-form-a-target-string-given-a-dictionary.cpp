class Solution {
public:
    int freq[1001][26];
    int dp[1001][1001];
    int n, m;
    const int mod = 1e9 + 7;
    int fixMod(long long x) { return x % mod; }

    string pat;
    int solve(int i, int j) {
        if (j == m)
            return 1;
        if (i == n)
            return 0;
        int& ret = dp[i][j];
        if (~ret)
            return ret;
        ret = 0;
        ret += fixMod(solve(i + 1, j));
        long long cnt = freq[i][pat[j] - 'a'];
        if (cnt) {
            /// need optimization
            // for (int x = 0; x < cnt; x++)
            ret = fixMod(ret + solve(i + 1, j + 1) * cnt);
        }
        return ret;
    }
    int numWays(vector<string>& words, string target) {
        n = words[0].size(), m = target.size();
        pat = target;

        memset(dp, -1, sizeof(dp));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < words.size(); i++) {
                freq[j][words[i][j] - 'a']++;
            }
        }

        return solve(0, 0);
    }
};