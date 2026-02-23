
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long n = s.size();

        vector<bool> vis(1LL << k);
        for (int i = 0; i + (k - 1) < n; i++) {
            bitset<32> b;
            int cnt = 0;
            int j = i;
            while (j - i < k) {
                b[cnt++] = (s[j] == '1');
                j++;
            }
            int val = b.to_ullong();
            vis[val] = 1;
        }
        int cnt = count(vis.begin(), vis.end(), true);
        return cnt == (1LL << k);
    }
};