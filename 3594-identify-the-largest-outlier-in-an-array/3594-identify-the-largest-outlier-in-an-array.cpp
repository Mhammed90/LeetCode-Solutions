class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int add = 1000;
        vector<int> freq(2 * add + 5);
        int tot = 0;
        for (int i = 0; i < n; i++) {
            freq[nums[i] + add]++;
            tot += nums[i];
        }
        int mx = -2000;
        for (int i = 1000; i >= -1000; i--) {
            if (freq[i + add] > 0) {
                int rem = tot - i;
                if (abs(rem) % 2 == 0) {
                    int mid = rem / 2;
                    int cur = mid + add;
                    if (cur >= 0 && cur <= 2000 && freq[cur]) {
                        if (mid == i) {
                            if (freq[cur] > 1) {
                                return i;
                            }
                        } else if (freq[cur]) {
                            return i;
                        }
                    }
                }
            }
        }

        return mx;
    }
};