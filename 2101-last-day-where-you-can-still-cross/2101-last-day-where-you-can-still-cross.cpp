class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<bool>> vis;
    vector<vector<int>> id;
    int n, m;
    bool okNow;

    bool valid(int i, int j) {
        return i >= 1 && j >= 1 && i <= n && j <= m && !vis[i][j];
    }

    void solve(int i, int j, int mid) {
        if (okNow)
            return;
        vis[i][j] = true;
        if (i == n) {
            okNow = true;
            return;
        }
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];
            if (valid(nx, ny) && id[nx][ny] >= mid) {
                solve(nx, ny, mid);
            }
        }
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row, m = col;
        id.assign(n + 1, vector<int>(m + 1));
        int sz = n * m;

        for (int i = 0; i < sz; i++) {
            id[cells[i][0]][cells[i][1]] = i + 1;
        }

        int l = 1, r = sz, ans = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            vis.assign(n + 1, vector<bool>(m + 1, false));
            okNow = false;

            for (int j = 1; j <= m; j++) {
                if (!vis[1][j] && id[1][j] >= mid) {
                    solve(1, j, mid);
                }
            }

            if (okNow) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans - 1;
    }
};
