class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size();
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {events[i][0], events[i][2]};
        }
        sort(p.begin(), p.end());
        vector<int> mx(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = max(mx[i + 1], p[i].second);
        }

        int sum = 0;

        for (int i = 0; i < n; i++) {
            int s = events[i][1];
            sum = max(sum, events[i][2]);
            int l = 0, r = n - 1, idx = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (p[mid].first > s) {
                    r = mid - 1;
                    idx = mid;
                } else
                    l = mid + 1;
            }
            if (idx != -1)
                sum = max(sum, events[i][2] + mx[idx]);
        }
        return sum;
    }
};