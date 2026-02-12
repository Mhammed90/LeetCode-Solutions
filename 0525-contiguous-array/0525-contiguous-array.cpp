class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, pre = 0;
        map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            pre += (nums[i] == 0 ? -1 : 1);
            if (mp.count(pre) == 0) {
                mp[pre] = i;
            } else
                ans = max(ans, i - mp[pre]);
        }
        return ans;
    }
};