class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long sum = 0, ans = 0;
        int i = 0, n = coins.size();
        while (sum < target) {
            if (i < n && coins[i] <= sum + 1) {
                sum += coins[i];
                i++;
            } else {
                sum <<= 1;
                sum++;
                ans++;
            }
        }

        return ans;
    }
};