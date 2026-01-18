class Solution {
public:
    int row[51][51], col[51][51];
    int diag1[51][51], diag2[51][51];

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i][j] = grid[i][j] + (j ? row[i][j - 1] : 0);
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                col[j][i] = grid[i][j] + (i ? col[j][i - 1] : 0);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diag1[i][j] = grid[i][j] +
                              ((i && j) ? diag1[i - 1][j - 1] : 0);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                diag2[i][j] = grid[i][j] +
                              ((i && j + 1 < m) ? diag2[i - 1][j + 1] : 0);
            }
        }

        for (int len = min(n, m); len >= 2; len--) {
            for (int i = 0; i + len - 1 < n; i++) {
                for (int j = 0; j + len - 1 < m; j++) {

                    int x = i + len - 1;
                    int y = j + len - 1;

                    int target = row[i][y] - (j ? row[i][j - 1] : 0);
                    bool ok = true;

                    for (int r = i; r <= x && ok; r++) {
                        int s = row[r][y] - (j ? row[r][j - 1] : 0);
                        if (s != target) ok = false;
                    }

                    for (int c = j; c <= y && ok; c++) {
                        int s = col[c][x] - (i ? col[c][i - 1] : 0);
                        if (s != target) ok = false;
                    }

                    int d1 = diag1[x][y] -
                             ((i && j) ? diag1[i - 1][j - 1] : 0);
                    if (d1 != target) ok = false;

                    int d2 = diag2[x][j] -
                             ((i && y + 1 < m) ? diag2[i - 1][y + 1] : 0);
                    if (d2 != target) ok = false;

                    if (ok) return len;
                }
            }
        }

        return 1; 
    }
};
