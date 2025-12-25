
class Solution {
public:
    int n, k;
    long long dp[20005][3], v[20005];

    long long solve(int i, int tak) {
        if (tak == 3)
            return 0;
        if (i + k - 1 > n)
            return -1e18;
        long long& ret = dp[i][tak];
        if (~ret)
            return ret;

        ret = max(solve(i + 1, tak),
                  solve(i + k, tak + 1) + (v[i + k - 1] - v[i - 1]));

        return ret;
    }

    vector<int> ans;

    void build(int i, int tak) {
        if (tak == 3)
            return;
        if (i + k - 1 > n)
            return;
        if ((v[i + k - 1] - v[i - 1]) + solve(i + k, tak + 1) ==
            solve(i, tak)) {
            ans.push_back(i - 1);
            build(i + k, tak + 1);
            return;
        }
        build(i + 1, tak);
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        k = K;
        n = nums.size();
        for (int i = 0; i < n; i++)
            v[i + 1] = v[i] + nums[i];

        memset(dp, -1, sizeof dp);
        solve(1, 0);
        build(1, 0);
        return ans;
    }
};
