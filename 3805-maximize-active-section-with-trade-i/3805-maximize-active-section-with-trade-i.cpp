class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i = 0, ans = 0, n = s.size(), sum = 0;
        vector<pair<int, int>> temp;
        temp.push_back({1, 0});
        temp.push_back({1, 0});

        while (i < n) {
            char cur = s[i];
            int cnt = 1;
            while (i + 1 < n && cur == s[i + 1])
                i++, cnt++;
            i++;
            if (cur - '0')
                sum += cnt;
            temp.push_back({cur - '0', cnt});
        }
        temp.push_back({1, 0});
        temp.push_back({1, 0});
        ans = sum;
        for (int i = 2; i < temp.size() - 2; i++) {
            if (temp[i].first && temp[i - 1].first == 0 &&
                temp[i + 1].first == 0) {
                ans = max(ans, sum + temp[i - 1].second + temp[i + 1].second);
            }
        }
        return ans;
    }
};