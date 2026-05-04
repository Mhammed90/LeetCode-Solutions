class Solution {
public:
    int minCost(vector<vector<int> > &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool> > > vis(n + 1, vector<vector<bool> >(m + 1, vector<bool>(1025, false)));
        queue<pair<pair<int,int>, int> > q;
        q.push(make_pair(pair<int, int>(0, 0), grid[0][0]));
        vis[0][0][grid[0][0]] = true;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i = p.first.first, j = p.first.second;
            int val = p.second;
            if (i + 1 < n) {
                int newXor = grid[i + 1][j] ^ val;
                if (!vis[i + 1][j][newXor]) {
                    vis[i + 1][j][newXor] = true;
                    q.push(make_pair(pair<int, int>(i + 1, j), newXor));
                }
            }
            if (j + 1 < m) {
                int newXor = grid[i][j + 1] ^ val;
                if (!vis[i][j + 1][newXor]) {
                    vis[i][j + 1][newXor] = true;
                    q.push(make_pair(pair<int, int>(i, j + 1), newXor));
                }
            }
        }

        for (int i = 0; i <= 1024; i++) {
            if (vis[n - 1][m - 1][i])return i;
        }
        return 0;
    }
};
