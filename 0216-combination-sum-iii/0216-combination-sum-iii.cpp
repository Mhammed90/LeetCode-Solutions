class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> kepp;
        vector<vector<int>> res;

        for (int i = 0; i < (1 << 10); i++) {
            int sum = 0;
            vector<int> st;
            for (int j = 1; j <= 9; j++) {
                if ((i >> j) & 1) {
                    sum += j;
                    st.push_back(j);
                }
            }
            if (sum == n && st.size() == k) {
                kepp.insert(st);
            }
        }

        for (auto i : kepp) {
            res.push_back(i);
        }

        return res;
    }
};