class Solution {
public:
    int getLen(vector<int>& bars) {
        int n = bars.size();
        sort(bars.begin(), bars.end());
        int len = 1, mxLen = 1;
        for (int i = 1; i < n; i++) {
            if (bars[i] == 1 + bars[i - 1])
                len++;
            else
                len = 1;
            mxLen = max(mxLen, len);
        }

        return mxLen;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {

        int len = 1 + min(getLen(hBars), getLen(vBars));

        return len * len;
    }
};