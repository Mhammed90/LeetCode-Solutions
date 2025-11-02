class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<bool>> vis;

    bool valid(int i, int j, int n, int m) {
        return min(i, j) >= 0 && i < n && j < m;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        swap(n, m);
        vis.resize(n + 2, vector<bool>(m + 2));
        vector<vector<int>> g(n + 2, vector<int>(m + 2));
        for (auto i : guards) {
            g[i[0]][i[1]] = 1;
        }
        for (auto i : walls) {
            g[i[0]][i[1]] = 2;
        }
        int ans = (n * m) - (walls.size() + guards.size());
        for (auto e : guards) {
            int i = e[0], j = e[1];
            for (int d = 0; d < 4; d++) {
                int nx = dx[d] + i, ny = dy[d] + j;
                while (valid(nx, ny, n, m) && g[nx][ny] == 0) {
                    ans -= (g[nx][ny] == 0 && vis[nx][ny] == 0);
                    vis[nx][ny] = 1;
                    nx = dx[d] + nx, ny = dy[d] + ny;
                }
            }
        }
        return ans;
    }
};