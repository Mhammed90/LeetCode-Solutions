class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int st = nums[0];
        int n = nums.size(), mnCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= st) {
                mnCount++;
                st = nums[i];
            }
        }
        if (st != nums[0] || mnCount > 1) {
            return 0;
        }
        const int Mod = 1e9 + 7;
        long long a = 1, b = 1;
        for (int i = 2; i < n; i++) {
            b = (a * 1LL * i) % Mod;
            a = b;
        }

        return b;
    }
};