class Solution {
public:
    int freq[100005][26];
    vector<int> get(int idx) {
        vector<int> ret(26, 0);
        if (idx == -1)
            return ret;
        for (int i = 0; i < 26; i++) {
            ret[i] = freq[idx][i];
        }
        return ret;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            freq[i][s[i] - 'a']++;
            if (i)
                for (int j = 0; j < 26; j++)
                    freq[i][j] += freq[i - 1][j];
        }

        vector<bool> res(queries.size(), 1);

        int idx = 0;
        for (auto i : queries) {
            int l = i[0], r = i[1], k = i[2];
            vector<int> a = get(r);
            vector<int> b = get(l - 1);
            int cnt = 0;
            for (int j = 0; j < 26; j++) {
                a[j] = a[j] - b[j];
                cnt += (a[j] & 1);
            }
            if ((r - l + 1) & 1) {
                cnt--;
            }
            cnt >>= 1;
            if (cnt > k)
                res[idx] = 0;
            idx++;
        }

        return res;
    }
};