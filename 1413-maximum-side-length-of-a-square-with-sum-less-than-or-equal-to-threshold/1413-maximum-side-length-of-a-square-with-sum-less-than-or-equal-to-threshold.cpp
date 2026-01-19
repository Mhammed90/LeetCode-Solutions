class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] +
                             pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }
        for (int len = min(n, m); len >= 1; len--) {
            for (int i = len; i <= n; i++) {
                for (int j = len; j <= m; j++) {
                    int sum = pref[i][j] - pref[i - len][j] - pref[i][j - len] +
                              pref[i - len][j - len];

                    if (sum <= threshold)
                        return len;
                }
            }
        }

        return 0;
    }
};