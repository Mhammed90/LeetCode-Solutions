class Solution {

public:
    int specialTriplets(vector<int>& nums) {

        const int MOD = 1e9 + 7;

        map<long long, long long> right, left;

        for (int v : nums)
            right[v]++;

        long long ans = 0;

        for (int j = 0; j < (int)nums.size(); ++j) {

            long long x = nums[j];

            --right[x];

            if (right[x] == 0)
                right.erase(x);

            long long need = 2 * x;

            long long cnL = left.count(need) ? left[need] : 0;

            long long cnR = right.count(need) ? right[need] : 0;

            ans = (ans + (cnL * cnR) % MOD) % MOD;

            left[x]++;
        }

        return ans;
    }
};