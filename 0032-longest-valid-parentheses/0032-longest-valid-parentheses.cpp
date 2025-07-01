class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        stack<int> st;
        vector<int> arr(n);
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((st.empty() && s[i] == '(') || s[i] == '(') {
                st.push(i);
            } else {
                if (st.size()) {
                    arr[st.top()] = 1;
                    arr[i] = 1;
                    st.pop();
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                cnt = 0;
            else
                cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};