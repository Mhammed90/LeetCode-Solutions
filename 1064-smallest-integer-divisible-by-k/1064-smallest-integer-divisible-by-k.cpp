class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long n = 1;
        for (int i = 1; i <=k; i++) {
            if (n % k == 0) {
                return i;
            }
            n = n * 10ll + 1ll;
            n %= k;
        }
        return -1;
    }
};