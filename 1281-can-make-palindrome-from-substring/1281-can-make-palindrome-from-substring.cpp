class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i] = 1 << (s[i] - 'a');
            if (i)
                dp[i] ^= dp[i - 1];
        }
        vector<bool> res(queries.size(), 1);
        int idx = 0;
        for (auto i : queries) {
            int l = i[0], r = i[1], k = i[2];
            int val = dp[r] ^ (l ? dp[l - 1] : 0);
            int cnt = 0;
            for (int j = 0; j < 26; j++) {
                if ((val >> j) & 1)
                    cnt++;
            }
            cnt >>= 1;
            if (cnt > k)
                res[idx] = 0;
            idx++;
        }

        return res;
    }
};