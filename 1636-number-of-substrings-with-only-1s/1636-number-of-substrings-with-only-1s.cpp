class Solution {
public:
    int numSub(string s) {
        int n = s.size(), ans = 0;
        int cnt = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                cnt = 0;
            else
                cnt++;
            ans += cnt;
            ans %= (mod);
        }
        return ans;
    }
};