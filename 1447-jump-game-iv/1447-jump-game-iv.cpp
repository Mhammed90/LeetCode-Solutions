class Solution {
public:
    unordered_map<int, vector<int>> mp;
    int d[50005];
    vector<int> adj[50005];
    int minJumps(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
            d[i] = n + 1;
            mp[a[i]].push_back(i);
        }
        deque<int> q;
        d[0] = 0;
        q.push_back(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (int u : mp[a[v]]) {
                if (d[u] > d[v] + 1) {
                    d[u] = d[v] + 1;
                    q.push_back(u);
                }
            }
            mp[a[v]].clear();
            for (int u : adj[v]) {
                if (d[u] > d[v] + 1) {
                    d[u] = d[v] + 1;
                    q.push_back(u);
                }
            }
        }

        return d[n - 1];
    }
};