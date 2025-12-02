class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> mp;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto x : points) {
            mp[x[1]]++;
        }
        for (auto& i : mp) {
            long long x = (long long)i.second * (i.second - 1) / 2;
            ans += x * sum;
            sum += x;
        }
        return ans % mod;
    }
};