class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int n = intervals.size();
        stack<int> st;
        auto overlaps = [&](int i, int j) -> bool {
            return intervals[j][0] >= intervals[i][0] &&
                   intervals[j][0] < intervals[i][1];
        };

        for (int i = 0; i < n; i++) {
            if (st.empty())
                st.push(i);
            else if (overlaps(st.top(), i)) {
                int j = st.top();
                if (intervals[j][1] > intervals[i][1]) {
                    st.pop();
                    st.push(i);
                }
            } else
                st.push(i);
        }
        return n - st.size();
    }
};