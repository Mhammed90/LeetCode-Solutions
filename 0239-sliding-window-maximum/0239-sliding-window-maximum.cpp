class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();

        multiset<int> st;
        for (int i = 0; i < k; i++)
            st.insert(nums[i]);
        int j = 0;
        for (int i = k; i < n; i++) {
            res.push_back(*st.rbegin());
            st.erase(st.find(nums[j]));
            st.insert(nums[i]);
            j++;
        }
         res.push_back(*st.rbegin());
        return res;
    }
};