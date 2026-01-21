class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) { 
        vector<int>res;
        for (int num : nums) {
            int val = -1;
            for (int bit = 30; bit >= 0; bit--) {
                if (((num >> bit) & 1)) {
                    int x = (num - (1 << bit));
                    if ((x | (x + 1)) == num) {
                        val = x;
                        break;
                    }
                }
            }
            res.push_back(val);
        }
        return res;
    }
};