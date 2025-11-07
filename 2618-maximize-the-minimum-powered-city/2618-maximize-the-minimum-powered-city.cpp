
class Solution {
public:
    bool check(long long mid, int k, int r, vector<long long>& partial) {
        int n = partial.size();
        vector<long long> cur = partial;
        long long take = 0, prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += cur[i];
            if (prefix < mid) {
                long long dif = mid - prefix;
                take += dif;
                if (take > k)
                    return false;
                if (i + 2 * r + 1 < n) {
                    cur[i + 2 * r + 1] -= dif;
                }
                prefix = mid;
            }
        }
        return 1;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> partial(n);
        r *= 1LL;
        n *= 1LL;
        for (long long i = 0; i < n; i++) {
            partial[max(0LL, i - r)] += stations[i];
            if (min(n - 1LL, i + r) + 1LL < n)
                partial[min(n - 1LL, i + r) + 1LL] -= stations[i];
        }
        long long ans = partial[0], cur = ans;
        for (int i = 1; i < n; i++) {
            cur += partial[i];
            ans = min(ans, cur);
        }
        long long st = ans, en = 2e10;

        while (st <= en) {
            long long mid = (st + en) / 2;
            if (check(mid, k, r, partial)) {
                st = mid + 1;
                ans = mid;
            } else {
                en = mid - 1;
            }
        }
        return ans;
    }
};