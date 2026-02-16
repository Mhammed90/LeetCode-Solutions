class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        int cnt = 0;
        while (n) {
            if (n % 2) {
                ans += (1LL<< (31 - cnt));
            }
            cnt++;
            n /= 2;
        }
        return ans;
    }
};