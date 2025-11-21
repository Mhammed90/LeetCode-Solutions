class Solution {
public:
    struct node {
        int l, r;
    };

    int countPalindromicSubsequence(string s) {
        int n = s.size();
        node arr[26];
        memset(arr, -1, sizeof arr);

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            if (arr[x].l == -1)
                arr[x].l = i;
            arr[x].r = i;
        }
        int freq[26];
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i].l != -1) {
                memset(freq, 0, sizeof(freq));
                for (int j = arr[i].l + 1; j < arr[i].r; j++) {
                    freq[s[j] - 'a']++;
                }
                for (auto j : freq)
                    ans += j != 0;
            }
        }
        return ans;
    }
};