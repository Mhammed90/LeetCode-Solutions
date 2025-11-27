class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, long long> mp;
        mp[0] = 0;
        long long sum = 0, ans = -1e15;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.count((i + 1) % k) == 0) {
                mp[(i + 1) % k] = sum;
            } else {
                ans = max(ans, sum - mp[(i + 1) % k]);
                mp[(i + 1) % k] = min(sum, mp[(i + 1) % k]);
            }
        }
        return ans;
    }
};