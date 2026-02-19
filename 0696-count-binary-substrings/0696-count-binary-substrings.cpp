class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int cnt = 1, prev = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else {
                if (prev)
                    ans += min(prev, cnt);
                prev = cnt;
                cnt = 1;
            }
        }
        ans += min(prev, cnt);
        return ans;
    }
};