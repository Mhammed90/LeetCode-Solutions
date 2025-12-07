class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, sum = 0;
        deque<int> dq;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            dq.push_back(nums[i]);
            sum += nums[i];
            while (dq.size() && sum * dq.size() >= k) {
                sum -= dq.front();
                dq.pop_front();
            }
            ans += dq.size();
        }
        return ans;
    }
};