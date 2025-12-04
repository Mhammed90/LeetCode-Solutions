class Solution {
public:
    int countCollisions(string s) {

        int n = s.size();
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                ans += 2;
                s[i] = s[i + 1] = 'S';
            }
        }

        int r = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'S') {
                ans += r;
                r = 0;
            } else if (s[i] == 'R')
                r++;
            else {
                if (i && s[i - 1] == 'S') {
                    ans++;
                    while (i + 1 < n && s[i + 1] == 'L')
                        ans++,i++;
                }
            }
        }
        return ans;
    }
};