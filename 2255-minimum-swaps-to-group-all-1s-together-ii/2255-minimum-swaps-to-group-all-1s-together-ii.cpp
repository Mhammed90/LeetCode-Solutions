class Solution {
public:
    int prefx[200005];
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        for (int i = 0; i < 2 * n; i++) {
            prefx[i] = nums[i % n];
            if (i)
                prefx[i] += prefx[i - 1];
        }
        int ans =min(n,ones);
     if(ones)
        for (int i = 0; i + ones < 2 * n; i++) {
            int sub = prefx[i + ones-1] - (i ? prefx[i - 1] : 0);
            ans = min(ans, ones - sub);
        }
        return ans;
    }
};