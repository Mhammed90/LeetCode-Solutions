class Solution {
public:
      static const int INF = 1e9;
    int dp[505][505][2];

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][0] = -INF;
                dp[i][j][1] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int take = 0; take <= 1; take++) {

                    int op1 = dp[i + 1][j][take];
                    int op2 = dp[i][j + 1][take];
                    int takeBoth = nums1[i] * nums2[j] + dp[i + 1][j + 1][1];
                    dp[i][j][take] = max({op1, op2, takeBoth});
                }
            }
        }

        return dp[0][0][0]; 

    }
};