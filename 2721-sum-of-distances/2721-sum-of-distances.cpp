class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, vector<long long>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto v : mp) {
            auto cur = v.second;
            if (cur.size() < 1)
                continue;
            for (int i = 1; i < cur.size(); i++) {
                cur[i] += cur[i - 1];
            }
            long long sz = cur.size();

            for (int i = 0; i < sz; i++) {
                long long idx = cur[i] - (i ? cur[i - 1] : 0);
                res[idx] += (idx * i) - (i ? cur[i - 1] : 0);
                res[idx] +=
                    (i != sz - 1 ? (cur[sz - 1] - cur[i]) - (idx) * (sz - i - 1)
                                 : 0);
            }
        }

        return res;
    }
};