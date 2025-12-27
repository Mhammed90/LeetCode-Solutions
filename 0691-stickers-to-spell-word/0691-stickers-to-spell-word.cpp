class Solution {
public:
    vector<string> s;
    map<vector<int>, int> dp, vis;

    bool Ok(vector<int>& frq) {
        for (int i = 0; i < 26; i++) {
            if (frq[i])
                return 1;
        }
        return 0;
    }

    int solve(vector<int>& frq) {
        if (!Ok(frq))
            return 0;
        if (vis.count(frq))
            return dp[frq];
        vis[frq] = 1;
        int ret = 1e9;
        for (auto& i : s) {
            vector<int> temp = frq;
            int o = 0;
            for (char j : i) {
                if (temp[j - 'a'] > 0) {
                    temp[j - 'a']--;
                    o = 1;
                }
            }
            if (o)
                ret = min(ret, solve(temp) + 1);
        }
        return dp[frq] = ret;
    }

    int minStickers(vector<string>& stickers, string target) {
        s = stickers;
        vector<int> frq(26);
        vector<int> freq(26);
        for (auto i : target) {
            frq[i - 'a']++;
        }
        for (auto i : s) {
            for (auto j : i) {
                freq[j - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (frq[i] && !freq[i]) {
                return -1;
            }
        }
        return solve(frq);
    }
};