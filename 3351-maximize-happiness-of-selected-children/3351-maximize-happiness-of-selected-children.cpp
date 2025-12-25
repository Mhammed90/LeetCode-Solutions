class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        for (int i = 0; i < k; i++) {
            ans += max(0ll, 1LL * happiness[i] - i);
        }
        return ans;
    }
};
