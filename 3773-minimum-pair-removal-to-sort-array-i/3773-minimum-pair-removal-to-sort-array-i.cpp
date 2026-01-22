
class Solution {
public:
    vector<int> get(vector<int>& t, int idx) {
        vector<int> res;
        for (int i = 0; i < t.size(); i++) {
            if (i == idx) {
                res.push_back(t[idx] + t[idx + 1]);
                i++;
                continue;
            }
            res.push_back(t[i]);
        }
        return res;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int sz = n;
        while (!is_sorted(nums.begin(), nums.end())) {
            n = nums.size();
            int idx = -1, mx = 1000000000;
            for (int i = 0; i + 1 < n; i++) {
                if (mx > nums[i] + nums[i + 1]) {
                    mx = nums[i] + nums[i + 1];
                    idx = i;
                }
            }
            nums = get(nums, idx);
        }

        return sz - nums.size();
    }
};