class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        vector<long long> v[n];
        vector<pair<int, int>> temp;
        for (int i = 0; i < meetings.size(); ++i)
            temp.push_back({meetings[i][0], meetings[i][1]});
        sort(temp.begin(), temp.end());
        long long mx = 0, id = 0;
        for (int i = 0; i < temp.size(); i++) {
            long long mn = 1e18, done = 0, idx = -1;
            for (int j = 0; j < n; j++) {
                if (v[j].size() == 0 || v[j].back() <= temp[i].first) {
                    done = 1;
                    v[j].push_back(temp[i].second);
                    break;
                }
            }
            if (!done) {
                for (int x = 0; x < n; x++) {
                    if (v[x].back() < mn) {
                        mn = min(mn, v[x].back());
                        idx = x;
                    }
                }
                v[idx].push_back((long long)temp[i].second - temp[i].first +
                                 v[idx].back());
            }
        }
        for (int i = 0; i < n; i++) {
            if (mx < v[i].size()) {
                mx = v[i].size();
                id = i;
            }
        }

        return id;
    }
};