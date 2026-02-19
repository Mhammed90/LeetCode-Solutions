class Solution {
public:
    long long dp[100005];
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long& ret = dp[i];
            if (i + 1 < n && colors[i] == colors[i + 1])
                ret = max(dp[i + 2] + nums[i], dp[i + 1]);
            else
                ret = dp[i + 1] + nums[i];
        }
        return max(dp[1], dp[0]);
    }
};