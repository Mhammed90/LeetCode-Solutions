class Solution {
public:
    int cnt(long long n) {
        if (n <= 4)
            return 1;
        return cnt(n / 4) + 1;
    }
    long long binpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a;
            a = (1LL * a * a);
            b >>= 1;
        }
        return res;
    }
    bool isPowerOfFour(long long n) {
        int c = cnt(n);
        long long st = 1;
        if (n < -1)
            st = -1;
        for (int i = 0; i <= c; i++) {
            if (st > n) {
                return 0;
            }
            if (st == n) {
                return 1;
            }
            st *= 4LL;
        }

        return 0;
    }
};