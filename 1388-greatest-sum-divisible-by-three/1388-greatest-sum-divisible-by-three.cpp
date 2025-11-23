class Solution {
public:
    int dp[40004][3];
    vector<int> arr;
    int solve(int i, int mod) {
        if (i == arr.size()) {
            if (mod)
                return -10000000;
            return 0;
        }
        int& ret = dp[i][mod];
        if (~ret)
            return ret;
        ret = 0;
        ret = max(solve(i + 1, mod), solve(i + 1, (arr[i] + mod) % 3)+arr[i]);
        return ret;
    }
    int maxSumDivThree(vector<int>& nums) {
        arr = nums;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};