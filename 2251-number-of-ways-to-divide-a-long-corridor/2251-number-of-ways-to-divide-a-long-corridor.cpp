class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        const int MOD = 1e9 + 7;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                temp.push_back(i);
            }
        }
        if ((temp.size() & 1) || temp.size() == 0)
            return 0;
        int ans = 1;
        for (int i = 2; i < temp.size(); i += 2) {
            int dif = (temp[i] - temp[i - 1]);
            ans = (1LL * ans * dif) % MOD;
        }

        return ans;
    }
};