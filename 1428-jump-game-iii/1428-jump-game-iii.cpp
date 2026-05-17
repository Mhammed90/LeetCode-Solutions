class Solution {
public:
    bool vis[50005];
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        int mn = arr[start];
        while (q.size()) {
            int u = q.front();
            mn = min(mn, arr[u]);
            q.pop();
            if (!vis[u]) {
                vis[u] = 1;
                int x = u + arr[u];
                if (x < n && !vis[x])
                    q.push(x);
                x = u - arr[u];
                if (x >= 0&& !vis[x])
                    q.push(x);
            }
        }
        return mn == 0;
    }
};