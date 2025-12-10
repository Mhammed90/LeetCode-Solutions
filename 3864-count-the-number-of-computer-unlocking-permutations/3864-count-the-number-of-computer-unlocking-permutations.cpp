class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int mn = nums[0];
        int n = nums.size(), mnCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mn) {
                mnCount++;
                mn = nums[i];
            }
        }
        if (mn != nums[0] || mnCount > 1) {
            return 0;
        }
        const int Mod = 1e9 + 7;
        long long f = 1;
        for (int i = 2; i < n; i++) {
            f = (f * 1LL * i) % Mod;
        }

        return f;
    }
};