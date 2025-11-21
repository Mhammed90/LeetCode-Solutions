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
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i].l != -1) {
                set<char> st;
                for (int j = arr[i].l + 1; j < arr[i].r; j++) {
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }
        return ans;
    }
};