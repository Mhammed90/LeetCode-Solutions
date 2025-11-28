class Solution {
public:
    vector<int> adj[30005];

    long long sum[30005], ans = 0;

    void dfs(int u, int p, vector<int>& values, int k) {
        sum[u] = values[u];
        for (auto v : adj[u]) {
            if (v != p) {
                dfs(v, u, values, k);
                sum[u] += sum[v];
            }
        }
        if (sum[u] % k == 0) {
            ans++;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, 0, values, k);
        return ans;
    }
};