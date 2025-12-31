class Solution {
public:
    int dp[505][505];
    int solve(int i, int j, const string& word1, const string& word2) {
        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;

        int& ret = dp[i][j];
        if (~ret)
            return ret;
        ret = 505;
        ret = solve(i + 1, j, word1, word2) + 1;

        if (j < word2.size() && i < word1.size()) {
            ret = min(ret, solve(i + 1, j + 1, word1, word2) +
                               (word1[i] != word2[j]));
            ret = min(ret, solve(i, j + 1, word1, word2) + 1);
        }

        return ret;
    }
    int minDistance(string word1, string word2) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, word1, word2);
    }
};