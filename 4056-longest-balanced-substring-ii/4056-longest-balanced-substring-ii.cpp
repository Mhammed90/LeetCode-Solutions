class Solution {
public:
    int findMaxLengthForTwo(string& s, char c1, char c2) {
        int n = s.size();
        int ans = 0, pre = 0;
        map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != c1 && s[i] != c2) {
                mp.clear();
                mp[0] = i;
                pre = 0;
                continue;
            }
            pre += (s[i] == c1 ? -1 : 1);
            if (mp.count(pre) == 0) {
                mp[pre] = i;
            } else
                ans = max(ans, i - mp[pre]);
        }
        return ans;
    }
    int findMaxLengthForThree(string& s) {
        vector<int> cnt(3, 0);

        map<vector<int>, int> pos;
        pos[{0, 0}] = -1;

        int ans = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            cnt[s[i] - 'a']++;

            vector<int> key = {cnt[1] - cnt[0], cnt[2] - cnt[0]};

            if (pos.find(key) != pos.end()) {
                ans = max(ans, i - pos[key]);
            } else {
                pos[key] = i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {

        int n = s.size(), ans = 1;

        /// case 1: mx number continues subarray of equal char
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else
                cnt = 1;
            ans = max(ans, cnt);
        }
        /// case 2  find 2 numbers equal

        ans = max({ans, findMaxLengthForTwo(s, 'a', 'b'),
                   findMaxLengthForTwo(s, 'a', 'c'),
                   findMaxLengthForTwo(s, 'b', 'c')});

        /// case 3 find 3 equel numbers

        ans = max(ans, findMaxLengthForThree(s));

        return ans;
    }
};