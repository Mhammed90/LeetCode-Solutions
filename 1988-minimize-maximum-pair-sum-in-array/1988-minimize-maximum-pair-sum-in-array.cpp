class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i] + nums[n - i - 1]);
        }

        return mx;
    }
};