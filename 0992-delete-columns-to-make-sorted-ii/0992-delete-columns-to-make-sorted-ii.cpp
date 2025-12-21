class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        vector<string> res(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j] += strs[j][i];
            }
            if (!is_sorted(res.begin(), res.end())) {
                ans++;
                for (int j = 0; j < n; j++)
                    res[j].pop_back();
            }
        }
        return ans;
    }
};