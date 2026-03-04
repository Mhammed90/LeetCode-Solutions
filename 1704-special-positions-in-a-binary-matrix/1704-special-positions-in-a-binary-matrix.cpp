class Solution {
public:
    int frqRows[101], frqCols[101];
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    frqRows[i]++;
                    frqCols[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    if (max(frqRows[i], frqCols[j]) == 1)
                        ans++;
                }
            }
        }
        return ans;
    }
};