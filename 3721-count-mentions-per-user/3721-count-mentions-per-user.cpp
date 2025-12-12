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
        for (auto& i : events) {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
            if (i[1] == "MESSAGE") {
                if (i[2] == "HERE") {
                    for (int j = 0; j < m; j++) {
                        if (stoi(i[0]) >= TimeOffLine[j]) {
                            Online[j] = 1;
                        }
                        res[j] += Online[j];
                    }
                } else if (i[2] == "ALL") {
                    for (int j = 0; j < m; j++)
                        res[j]++;
                } else {

                    vector<int> vis(m);
                    string x = i[2];
                    string t = "";
                    for (int j = 0; j < x.size(); j++) {
                        if (x[j] == 'i' || x[j] == 'd' || x[j] == ' ') {
                            if (t.size()) {
                                int idx = stoi(t);
                                vis[idx]++;
                               // Online[idx] = 1;
                             //   TimeOffLine[idx] = 0;
                            }
                            t.clear();

                        } else {
                            t += x[j];
                        }
                    }
                    if (t.size()) {
                        int idx = stoi(t);
                        vis[idx]++;
                       // Online[idx] = 1;
                      //  TimeOffLine[idx] = 0;
                    }
                    for (int j = 0; j < m; j++) {
                        res[j] += vis[j];
                    }
                }
            } else {
                int idx = stoi(i[2]);
                TimeOffLine[idx] = stoi(i[0]) + 60;
                Online[idx] = 0;
            }
        }
        return res;
    }
};