class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int val = i;
            bool ok = 0;
            while (val) {
                int d = val % 10;
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    ok = 1;
                }
                if (d == 3 || d == 4 || d == 7) {
                    ok = 0;
                    break;
                }
                val /= 10;
            }

            ans += ok;
        }

        return ans;
    }
};
