class Solution {
public:
    int vis[100005];
    vector<int> adj[100005];
    vector<int> ThisSet;

    void dfs(int u) {
        vis[u] = 1;
        ThisSet.push_back(u);
        for (int v : adj[u]) {
            if (vis[v] == 0) {
                dfs(v);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        for (int i = 0; i < allowedSwaps.size(); i++) {
            adj[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            adj[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                multiset<int> a, b;
                ThisSet.clear();
                dfs(i);
                for (auto it : ThisSet) {
                    a.insert(source[it]);
                    b.insert(target[it]);
                }

                for (auto it : a) {
                    auto it2 = b.find(it);
                    if (it2 != b.end()) {
                        b.erase(it2);
                    }
                }
                ans += (int)b.size();
            }
        }
        return ans;
    }
};