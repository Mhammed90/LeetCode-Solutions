class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[idx] < nums[i])
                idx = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[idx] != nums[i] && nums[i] * 2 > nums[idx])
                return -1;
        }
        return idx ;
    }
};