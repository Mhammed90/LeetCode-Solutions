class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int mn = 5;
            for (int j = max(0ll, nums[i] - 2ll); j <= nums[i] + 2; j++) {
                if (j % 3 == 0) {
                    mn = min(mn, abs(j - nums[i]));
                }
            }
            ans += mn;
        }
        return ans;
    }
};