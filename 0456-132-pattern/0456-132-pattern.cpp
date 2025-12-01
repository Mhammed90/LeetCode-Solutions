class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMin(n + 5), suffMax(n + 5);
        prefMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefMin[i] = min(prefMin[i - 1], nums[i]);
        }
        set<int> st;
        for (int i = n - 1; i >= 0; i--) {
            st.insert(nums[i]);
            auto it = st.lower_bound(nums[i]);
            if (it == st.begin()) {
                suffMax[i] = -1e9 - 5;
            } else {
                --it;
                suffMax[i] = *it;
            }
        }

        for (int i = 1; i + 1 < n; i++) {
            int a = prefMin[i - 1], b = nums[i], c = suffMax[i];
            if (b > a && c != -1e9 - 5 && c > a && b > c) {
                return true;
            }
        }
        return false;
    }
};