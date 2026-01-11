class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {

        int n = heights.size();
        stack<int> st;
        vector<int> left(n, -1), right(n, n );

        for (int i = 0; i < n; i++) {
            while (st.size() && heights[st.top()] > heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size())st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && heights[st.top()] >heights[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << left[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << right[i] << " ";
        // }
        // cout << endl;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, ((right[i] - left[i] - 1)) * heights[i]); 
            // ans=max(ans,heights[i]);
            // ans = max(ans, (left[i] - i + 1) * heights[i]);
            // ans = max(ans, (i - right[i]) * heights[i]);
        }
        return ans;
    }
};
