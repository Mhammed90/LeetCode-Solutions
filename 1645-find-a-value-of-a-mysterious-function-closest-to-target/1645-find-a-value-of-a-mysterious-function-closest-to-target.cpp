class Solution {
public:
    int freq[100005][32];

    int closestToTarget(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if ((nums[i] >> j) & 1)
                    freq[i][j]++;
            }

            /// build prefix
            if (i) {
                for (int j = 0; j < 30; j++) {
                    freq[i][j] += freq[i - 1][j];
                }
            }
        }

        long long ans = 1e10;

        for (int i = 0; i < n; i++) {
            int l = i, r = n - 1, idx = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                long long cur = 0;
                for (int j = 0; j < 30; j++) {
                    if (freq[mid][j] - (i ? freq[i - 1][j] : 0) ==
                        (mid - i + 1))
                        cur += (1LL << j);
                }
                if (cur >= target) {
                    l = mid + 1;
                    idx = mid;
                } else {
                    r = mid - 1;
                }
            }

            for (int x = max(i, idx - 20); x < min(idx + 20, n); x++) {
                long long cur = 0ll;
                for (int j = 0; j < 30; j++) {
                    if (freq[x][j] - (i ? freq[i - 1][j] : 0) == (x - i + 1))
                        cur += (1LL << j);
                }
                ans = min(ans, llabs(cur - target));
            }
        }
        return ans;
    }
};

/*


get anding for range we can use 2d freq for the one bits what will give

       anding of reanges decreas not increase


       as bit will close

       so we can binary search for the closet value to target



*/