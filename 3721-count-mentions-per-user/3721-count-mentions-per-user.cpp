class Solution {
public:
    vector<int> countMentions(int m, vector<vector<string>>& events) {

        vector<int> TimeOffLine(m), Online(m), res(m);
        for (auto& i : events) {
            swap(i[0], i[1]);
        }
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 if (stoi(a[0]) != stoi(b[0]))
                     return stoi(a[0]) < stoi(b[0]);
                 return a[1] > b[1];
             });
        int cnt = 0;
        for (auto& i : events) {
            if (i[1][0] == 'M') {
                if (i[2][0] == 'H') {
                    for (int j = 0; j < m; j++) {
                        if (stoi(i[0]) >= TimeOffLine[j]) {
                            Online[j] = 1;
                        }
                        res[j] += Online[j];
                    }
                } else if (i[2][0] == 'A') {
                    cnt++;
                } else {
                    string x = i[2];
                    string t = "";
                    for (int j = 0; j < x.size(); j++) {
                        if (x[j] == 'i' || x[j] == 'd' || x[j] == ' ') {
                            if (t.size()) {
                                int idx = stoi(t);
                                res[idx]++;
                            }
                            t.clear();

                        } else {
                            t += x[j];
                        }
                    }
                    int idx = stoi(t);
                    res[idx]++;
                }
            } else {
                int idx = stoi(i[2]);
                TimeOffLine[idx] = stoi(i[0]) + 60;
                Online[idx] = 0;
            }
        }
        if (cnt)
            for (int i = 0; i < m; i++)
                res[i] += cnt;
        return res;
    }
};