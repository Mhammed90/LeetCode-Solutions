class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        multiset<int> st;
        for (int i : nums)
            st.insert(i);
        while (k--) {
            auto it = st.begin();
            int val = *it;
            st.erase(it);
            st.insert(val + 1);
        }
        int MOD = 1e9 + 7;
        int ans = 1;
        for (int i : st) {
            ans = (i * ans) % MOD;
        }
        return ans;
    }
};