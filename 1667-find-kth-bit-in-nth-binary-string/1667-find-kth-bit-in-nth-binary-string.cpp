class Solution {
public:
 
    char findKthBit(int n, int k) {
        string cur = "0";
        for (int i = 1; i <= n; i++) {
            string x = cur + '1';
            reverse(cur.begin(), cur.end());
            for (char& j : cur) {
                j = (j == '0' ? '1' : '0');
            }

            cur = x + cur;
        }

        return cur[k - 1];
    }
};
