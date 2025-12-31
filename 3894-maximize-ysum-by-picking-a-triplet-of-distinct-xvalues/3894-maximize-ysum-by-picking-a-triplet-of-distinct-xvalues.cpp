class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = {y[i], x[i]};
        }
        sort(temp.begin(), temp.end());
        int a = 0, b = 0, c = 0, res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a == 0) {
                res = temp[i].first;
                a = temp[i].second;
            } else if (a && b == 0 && temp[i].second != a) {
                res += temp[i].first;
                b = temp[i].second;

            } else if (a && b && temp[i].second != a && temp[i].second != b) {
                res += temp[i].first;
                return res;
            }
        }
        return -1;
    }
};