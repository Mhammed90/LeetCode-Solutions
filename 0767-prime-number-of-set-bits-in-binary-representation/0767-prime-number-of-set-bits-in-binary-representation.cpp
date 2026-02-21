class Solution {
public:
    bool primes(int cnt) {
        return (cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 ||
                cnt == 13 || cnt == 17 || cnt == 19 || cnt == 23 || cnt == 29);
    }
    int countPrimeSetBits(int left, int right) {

        int ans = 0;
        for (int i = left; i <= right; i++) {
            int cnt = 0, cur = i;
            while (cur) {
                cnt += (cur % 2);
                cur /= 2;
            }
            ans += primes(cnt);
        }
        return ans;
    }
};