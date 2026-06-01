class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int sum = 0, n = cost.size();
        for (int i = n - 1; i >= 2; i -= 3) {
            sum += cost[i] + cost[i - 1];
        }
        for (int i = 0; i < n % 3; i++)
            sum += cost[i];
        return sum;
    }
};