class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefx(n), sum(n);

        for (int i = 0; i < n; i++) {
            prefx[i] = prices[i] * strategy[i];
            sum[i] += prices[i];
            if (i) {
                sum[i] += sum[i - 1];
                prefx[i] += prefx[i - 1];
            }
        }
        long long ans = prefx[n - 1];
        k /= 2;
        for (int i = k; i + k - 1 < n; i++) {
            ans = max(ans, (prefx[n - 1] -
                            (prefx[i + (k - 1)] -
                             (i - (k + 1) >= 0 ? prefx[i - (k + 1)] : 0))) +
                               (sum[i + k - 1] - sum[i - 1]));
        }
        return ans;
    }
};