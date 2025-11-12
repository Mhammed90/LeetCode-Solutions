class Solution {
public:
    int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int gc = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            gc = gcd(gc, nums[i]);
            cnt += nums[i] == 1;
        }
        int ans = -1;
        if (gc != 1) {
            ans = -1;
        } else {
            if (cnt)
                return ans = n - cnt;
            ans = n * 2;
            for (int i = 0; i < n; i++) {
                gc = nums[i];
                for (int j = i - 1; j >= 0; j--) {
                    gc = gcd(gc, nums[j]);
                    if (gc == 1) {
                        ans = min(ans, i - j + n - 1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};