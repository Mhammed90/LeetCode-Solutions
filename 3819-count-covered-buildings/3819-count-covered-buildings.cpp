class Solution {

public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> mnX(n + 5, n + 1), mxX(n + 5);
        vector<int> mnY(n + 5, n + 1), mxY(n + 5);
        for (auto i : buildings) {
            int x = i[0], y = i[1];
            mnX[x] = min(y, mnX[x]);
            mxX[x] = max(y, mxX[x]);
            mnY[y] = min(x, mnY[y]);
            mxY[y] = max(x, mxY[y]);
        }
        int ans = 0;
        for (auto i : buildings) {
            int y = i[0], x = i[1];
            if (x > mnX[y] && x < mxX[y] && y > mnY[x] && y < mxY[x])
                ans++;
        }
        return ans;
    }
};