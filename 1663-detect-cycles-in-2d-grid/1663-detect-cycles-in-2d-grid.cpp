class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int vis[505][505];
    int inStack[505][505];
    int n, m;

    bool valid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }

    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid) {
        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (!valid(ni, nj) || grid[ni][nj] != grid[i][j])
                continue;

            if (ni == pi && nj == pj)
                continue;

            if (vis[ni][nj]) {
                return true;
            }

            if (dfs(ni, nj, i, j, grid)) {
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && dfs(i, j, -1, -1, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
};