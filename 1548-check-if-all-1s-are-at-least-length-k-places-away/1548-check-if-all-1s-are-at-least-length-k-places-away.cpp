class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int f = 0, cnt = 0;
        int i = 0;
        while (i < nums.size() && !nums[i])
            i++;
        i++;
        for (; i < nums.size(); i++) {
            if (!nums[i])
                cnt++;
            else {
                if (cnt < k) {
                    return 0;
                }
                cnt = 0;
            }
        }
        return 1;
    }
};