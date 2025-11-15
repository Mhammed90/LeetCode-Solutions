class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        vector<int> left(n + 1, 0);
        left[0] = -1;
        left[1] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0') {
                left[i + 1] = i;
            } else {
                left[i + 1] = left[i];
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            int zeroes = 0;
            if (s[i - 1] == '0') {
                zeroes++;
            }

            int j = i;

            while (zeroes * zeroes <= n && j > 0) {
                int ones = i - left[j] - zeroes;
                if (zeroes * zeroes <= ones) {
                    ans += min(j - left[j], ones - zeroes * zeroes + 1);
                }
                j = left[j];
                zeroes++;
            }
        }

        return ans;
    }
};