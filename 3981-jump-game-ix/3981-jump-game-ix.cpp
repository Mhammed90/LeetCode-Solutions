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
        res[n - 1] = pref[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (pref[i] > sufx[i + 1]) {
                res[i] = max(res[i + 1], pref[i]);
            } else
                res[i] = pref[i];
        }

        return res;
    }
};