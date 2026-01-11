
class Solution {
public:
    int cnt[202][202];

    int maximalRectangle(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            stack<int> st;
            for (int j = 0; j < m; j++) {
                while (st.size() && grid[i][st.top()] - '0' > grid[i][j] - '0') {
                    cnt[i][st.top()] = j - st.top();
                    st.pop();
                }
                st.push(j);
            }
            while (st.size() && grid[i][st.top()] == '1') {
                cnt[i][st.top()] = m - st.top();
                st.pop();
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cnt[i][j]) {
                    int mn = cnt[i][j];
                    for (int x = i; x < n; x++) {
                        mn = min(mn, cnt[x][j]);
                        ans = max(ans, mn * (x - i + 1));
                    }
                }
            }
        }

        return ans;
    }
};