class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mn = nums[n - 1];
        for (int i = 0; i + k - 1 < n; i++) {

            mn = min(mn, nums[i + k - 1] - nums[i]);
        }
        return mn;
    }
};