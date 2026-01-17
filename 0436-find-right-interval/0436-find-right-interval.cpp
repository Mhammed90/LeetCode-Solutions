class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intr) {
        int n = intr.size();
        vector<pair<pair<int, int>, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {{intr[i][0], intr[i][1]}, i};
        }
        sort(p.begin(), p.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int endJ = p[i].first.second, I = p[i].second;
            int l = i, r = n - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (p[mid].first.first >= endJ) {
                    r = mid - 1;
                    idx = p[mid].second;
                } else
                    l = mid + 1;
            }

            ans[I] = idx;
        }

        return ans;
    }
};