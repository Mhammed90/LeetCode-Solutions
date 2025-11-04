class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(), idx = 0;
        vector<int> res(n - k + 1), freq(51);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (i + 1 >= k) {
                if (i >= k) {
                    freq[nums[i - k]]--;
                }
                vector<pair<int, int>> p;
                for (int j = 50; j >= 1; j--) {
                    if (freq[j]) {
                        p.push_back({freq[j], j});
                    }
                }
                sort(p.begin(), p.end());
                int cur = 0;
                for (int j = max(0, (int)p.size() - x); j < p.size(); j++) {
                    res[idx] += p[j].first * p[j].second;
                }
                idx++;
            }
        }
        return res;
    }
};