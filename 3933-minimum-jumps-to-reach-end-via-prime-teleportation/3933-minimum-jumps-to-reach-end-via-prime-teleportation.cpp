class Solution {
public:
    void buildSPF(vector<int> &SPF,int mx) {
        int N = mx;
        for (int i = 0; i < N; i++) {
            SPF[i] = i;
        }
        for (int i = 2; i < N; i++) {
            if (SPF[i] == i) {
                for (int j = i + i; j < N; j += i) {
                    if (SPF[j] == j)
                        SPF[j] = i;
                }
            }
        }
    }

    set<int> getPrims(int n, vector<int> &SPF) {
        set<int> s;
        while (n > 1) {
            s.insert(SPF[n]);
            n /= SPF[n];
        }
        return s;
    }

    int minJumps(vector<int> &nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int> > adj(mx + 1);
        vector<bool> vis(n+5, false);
        vector<int> SPF(mx + 5);
        buildSPF(SPF, mx + 5);
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            auto g = getPrims(nums[i], SPF);
            for (int j: g) {
                adj[j].push_back(i);
            }
        }

        vector<int> dis(n, n);
        queue<int> q;
        q.push(0);
        dis[0] = 0;
        while (!q.empty()) {
            auto u = q.front();
            int c = dis[u];
            q.pop();
            vis[u] = 1;
            if (u + 1 < n && !vis[u + 1]) {
                dis[u + 1] = min(c + 1, dis[u + 1]);
                q.push(u + 1);
            }
            if (u - 1 >= 0 && !vis[u - 1]) {
                dis[u - 1] = min(c + 1, dis[u - 1]);
                q.push(u - 1);
            }
            if (SPF[nums[u]] == nums[u]) {
                for (int p: adj[nums[u]]) {
                    if (!vis[p]) {
                        q.push(p);
                        dis[p] = min(dis[p], c + 1);
                    }
                }
                adj[nums[u]].clear();
            }
        }
        return dis[n - 1];
    }
};
