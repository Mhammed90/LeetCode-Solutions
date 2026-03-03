class Solution {
public:
    string solve(int n) {
        if (n == 0)
            return "0";

        string cur = solve(n - 1);

        string x = cur + '1';

        string rev = cur;
        reverse(rev.begin(), rev.end());

        for (char& c : rev) {
            c = (c == '0' ? '1' : '0');
        }

        return x + rev;
    }

    char findKthBit(int n, int k) { return solve(n)[k - 1]; }
};
