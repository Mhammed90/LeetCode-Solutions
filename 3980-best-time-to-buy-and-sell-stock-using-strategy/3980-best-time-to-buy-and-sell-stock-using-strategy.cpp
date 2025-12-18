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
        for (int i = k; i < n; i++) {
            if (i + k - 1 >= n)
                break;
            long long cur =
                prefx[n - 1] - (prefx[i + (k-1)] -
                                (i - (k + 1) >= 0 ? prefx[i - (k + 1)] : 0));

            cout << cur << endl;

            long long inc = sum[i + k - 1] - sum[i - 1];
            ans = max(ans, cur + inc);
        }
        return ans;
    }
};