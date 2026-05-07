class Solution {
public:
    bool vis[100005];
    vector<int> adj[100005];
    int mx = 0;
    vector<int> sol;

    void dfs(int u, vector<int>& nums) {
        vis[u] = true;
        sol.push_back(u);
        mx = max(mx, nums[u]);
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, nums);
            }
        }
    }

    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pref(n), sufx(n);
        pref[0] = nums[0];
        sufx[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            sufx[i] = min(sufx[i + 1], nums[i]);
        }

        for (int i = 0; i + 1 < n; i++) {
            if (pref[i] > sufx[i + 1]) {
                adj[i].push_back(i + 1);
                adj[i + 1].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                mx = 0;
                sol.clear();
                dfs(i, nums);
                for (auto j : sol)
                    res[j] = mx;
            }
        }
        return res;
    }
};