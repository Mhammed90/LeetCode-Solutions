class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lasPos = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (lasPos == -1)
                    lasPos = i;
                else if (i - lasPos-1 < k)
                    return 0;
                lasPos = i;
            }
        }
        return 1;
    }
};