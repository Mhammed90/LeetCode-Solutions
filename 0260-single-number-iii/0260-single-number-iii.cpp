class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xr ^= nums[i];
        } 
        xr &= -xr; 
        vector<int> res(2,0);
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & xr) == 0) {
                res[1] ^= nums[i];
            } else
                res[0] ^= nums[i];
        }

        return res;
    }
};