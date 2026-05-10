class Solution {
public:
    int dp[1005];
    int solve(int i, vector<int>& nums, int target) {
        if (i == nums.size() - 1)
            return 0;
        int& ret = dp[i];
        if (~ret)
            return ret;
        ret = -1e9;
        for (int j = i + 1; j < nums.size(); j++) {
            int x = nums[j] - nums[i];
            if (x <= target && x >= target * -1)
                ret = max(solve(j, nums, target) + 1, ret);
        }
        return ret;
    }

    int maximumJumps(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return max(-1, solve(0, nums, target));
    }
};