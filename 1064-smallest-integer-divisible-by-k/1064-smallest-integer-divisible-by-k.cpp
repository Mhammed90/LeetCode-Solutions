class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<long long> pre;
        long long n = 1;
        for (int i = 1; i < 50006; i++) {
            if (n % k == 0) {
                return i;
            }
            n = n * 10ll + 1ll;
            n %= k;
        }
        return -1;
    }
};