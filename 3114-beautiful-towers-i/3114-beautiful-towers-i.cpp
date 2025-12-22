class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i - 1, r = i + 1;
            int mn = heights[i];
            long long sum = mn;
            while (l >= 0) {
                mn = min(mn, heights[l]);
                sum += mn;
                l--;
            }
            mn = heights[i];
            while (r < n) {
                mn = min(mn, heights[r]);
                sum += mn;
                r++;
            }
            ans = max(ans, sum);
        }

        return ans;
    }
};