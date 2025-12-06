class Solution {
public:
    const int mod = 1e9 + 7;

    int dp[10006][6];
    int vis[10006][6], vid;

    string cur, pat;
    int n;
    int solve(int i, int j) {
        if (i == n) {
            return j == 5;
        }
        int& ret = dp[i][j];
        if (vis[i][j] == vid)
            return ret;
        vis[i][j] = vid;
        ret = 0;
        ret = solve(i + 1, j);

        if (j < 5 && cur[i] == pat[j])
            ret = (ret + solve(i + 1, j + 1)) % mod;

        return ret;
    }
    int countPalindromes(string s) {
        cur = s;
        n = s.size();
        set<string> st;
        string x(5, '0');
        for (char mid = '0'; mid <= '9'; mid++) {
            x[2] = mid;
            for (char i = '0'; i <= '9'; i++) {
                x[1] = x[3] = i;
                for (char j = '0'; j <= '9'; j++) {
                    x[0] = x[4] = j;
                    st.insert(x);
                }
            }
        }
        int ans = 0;
        for (auto i : st) {
            vid++;
            pat = i;
            ans += solve(0, 0);
            ans %= mod;
        }

        return ans;
    }
};