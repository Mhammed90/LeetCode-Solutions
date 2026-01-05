class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long long sum = 0;
        int neg = 0;
        int mn = INT_MAX;

        for (auto i : matrix) {
            for (int x : i) {
                sum += abs(x);
                if (x < 0)
                    neg++;
                mn = min(mn, abs(x));
            }
        }

        if (neg % 2 != 0)
            sum = sum - 2LL * mn;

        return sum;
    }
};