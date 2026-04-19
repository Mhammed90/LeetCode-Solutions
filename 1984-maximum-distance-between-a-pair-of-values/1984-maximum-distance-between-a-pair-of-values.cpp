
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int j = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && nums2[j] >= nums1[i]) {
                if (j >= i)
                    ans = max(ans, j - i);
                j++;
            }
        }
        return ans;
    }
};