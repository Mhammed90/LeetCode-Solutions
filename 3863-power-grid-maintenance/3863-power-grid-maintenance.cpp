
class Solution {
public:
    int vis[100005], id[100005];
    vector<int> adj[100005];
    deque<int> temp;
    vector<deque<int>> components;

    void dfs(int u, int p) {
        if (vis[u])
            return;
        vis[u] = 1;
        temp.push_back(u);
        for (auto v : adj[u]) {
            if (p != v)
                dfs(v, u);
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        for (auto e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                temp.clear();
                dfs(i, i);
                sort(temp.begin(), temp.end());
                components.push_back(temp);
            }
        }
        for (int i = 0; i < components.size(); i++) {
            for (auto j : components[i]) {
                /// id of the component
                id[j] = i;
                /// mark all is online
                vis[j] = 1;
            }
        }

        vector<int> res;

        for (auto e : queries) {
            int ty = e[0];
            int u = e[1];
            if (ty == 1) {
                int idx = id[u];
                while (components[idx].size() &&
                       !vis[components[idx].front()]) {
                    components[idx].pop_front();
                }
                if (vis[u])
                    res.push_back(u);
                else {
                    if (components[idx].size())
                        res.push_back(components[idx].front());
                    else
                        res.push_back(-1);
                }
            } else {
                vis[u] = 0;
            }
        }
        return res;
    }
};