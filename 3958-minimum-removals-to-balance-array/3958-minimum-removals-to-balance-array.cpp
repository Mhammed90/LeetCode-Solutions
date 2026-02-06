class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = n - 1;

        for (int i = 0; i < n; i++) {
            int idx = lower_bound(nums.begin(), nums.end(),
                                  1LL * nums[i] * 1LL * k + 1) -
                      nums.begin();
            ans = min(ans, (n - idx) + i);
        }

        return ans;
    }
};