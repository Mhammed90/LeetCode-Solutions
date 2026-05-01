class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i] * i;
            sum += nums[i];
        }
        int mx = total;
        for (int i = n - 1; i >= 0; i--) {
            total += sum - nums[i] * n; 
            mx = max(mx, total);
        }
        return mx;
    }
};