class Solution {
public:
    int binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        res %= m;
        return res;
    }
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n);
        int mod = 0;
        for (int i = 0; i < n; i++) {

            mod *= 2;
            mod += nums[i];
            mod %= 5;
            res[i] = (mod == 0);
        }
        return res;
    }
};