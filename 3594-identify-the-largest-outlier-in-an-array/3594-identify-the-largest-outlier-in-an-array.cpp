class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freq;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            tot += nums[i];
        }
        int mx = -20000;
        for (auto& i : freq) {
            i.second--;
            tot -= i.first;
            for (auto j : freq) {
                if (j.second) {
                    int sum = tot - j.first;
                    if (sum == j.first) {
                        mx = max(mx, i.first);
                    }
                }
            }
            i.second++;
            tot += i.first;
        }

        return mx;
    }
};