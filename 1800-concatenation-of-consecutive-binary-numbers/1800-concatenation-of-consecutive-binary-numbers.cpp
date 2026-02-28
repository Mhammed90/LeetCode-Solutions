class Solution {
public:
    int concatenatedBinary(int n) {

        long long ans = 0, MOD = 1e9 + 7;

        for (int i = 1; i <= n; i++) {
            int cur = i, cnt = 0;
            while (cur) {
                cur /= 2;
                cnt++;
            }
            ans = (ans << cnt*1LL) + i;
            ans %= MOD;
        }
        return ans;
    }
};