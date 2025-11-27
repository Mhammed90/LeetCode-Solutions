class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> mp(n + 5);
        for (int i = 0; i <= n; i++) {
            mp[i] = -1e15;
        }
        mp[0] = 0;
        long long sum = 0, ans = -1e15;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp[(i + 1) % k] == -1e15) {
                mp[(i + 1) % k] = sum;
            } else {
                ans = max(ans, sum - mp[(i + 1) % k]);
                mp[(i + 1) % k] = min(sum, mp[(i + 1) % k]);
            }
        }
        return ans;
    }
};