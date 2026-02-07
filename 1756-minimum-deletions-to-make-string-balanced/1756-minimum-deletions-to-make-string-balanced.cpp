class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        int countA = count(s.begin(), s.end(), 'a'), countB = 0;

        int ans = min(n - countA, countA);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                countA--;
            else
                countB++;
            ans = min(ans, countA + countB - (s[i] == 'b'));
        }

        return ans;
    }
};