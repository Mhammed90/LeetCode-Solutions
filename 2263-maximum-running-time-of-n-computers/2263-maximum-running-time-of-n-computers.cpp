class Solution {
public:
    long long maxRunTime(long long n, vector<int>& b) {
        int sz = b.size();
        vector<long long> prefixSum(sz);
        sort(b.begin(), b.end());
        prefixSum[0] = b[0];
        for (int i = 1; i < sz; i++) {
            prefixSum[i] += b[i] + prefixSum[i - 1];
        }
        long long ans = 0, l = 0, r = prefixSum[sz - 1] / n + 10;
        while (l <= r) {
            long long mid = (r + l) / 2;

            long long st = 0, en = sz - 1, idx = -1;
            while (st <= en) {
                int m = (st + en) / 2;
                if (prefixSum[m] - (m ? prefixSum[m - 1] : 0) <= mid) {
                    st = m + 1;
                    idx = m;
                } else
                    en = m - 1;
            }
            long long sum =
                (idx == -1 ? prefixSum[sz - 1]
                           : prefixSum[idx] + (mid * (sz - idx - 1)));
            if (sum >= (long long)n * mid) {
                l = mid + 1;
                ans = mid;
            } else
                r = mid - 1;
        }
        return ans;
    }
};
