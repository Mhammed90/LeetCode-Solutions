class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int mx = neededTime[0], curSum = mx;
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                curSum += neededTime[i];
                mx = max(mx, neededTime[i]);
            } else {
                ans += curSum - mx;
                mx = neededTime[i], curSum = mx;
            }
        }
        ans += curSum - mx;
        return ans;
    }
};