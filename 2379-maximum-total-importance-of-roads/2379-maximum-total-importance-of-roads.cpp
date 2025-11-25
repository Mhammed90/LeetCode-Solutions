class Solution {
public:
    int deg[50005];

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        for (auto e : roads) {
            deg[e[0]]++;
            deg[e[1]]++;
        }

        sort(deg, deg + n);
        int st = n;
        for (int i = n - 1; i >= 0; i--) {
            ans += 1LL*st * deg[i];
            st--;
        }
        return ans;
    }
};