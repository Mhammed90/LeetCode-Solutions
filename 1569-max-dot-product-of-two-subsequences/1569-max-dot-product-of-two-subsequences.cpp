class Solution {
public:
    int dp[505][505][2]; 
    int solve(int i, int j,bool takeAtLeastOne, const vector<int>& nums1,
              const vector<int>& nums2) {
        if (i == nums1.size() || j == nums2.size()) { 
            if(takeAtLeastOne)
            return 0; 

            return -1e9;
        }

        int& ret = dp[i][j][takeAtLeastOne];
        if (~ret)
            return ret;
        ret = -1e9;

        ret = max({solve(i + 1, j,takeAtLeastOne, nums1, nums2), solve(i, j + 1,takeAtLeastOne, nums1, nums2),
                   solve(i + 1, j + 1,1, nums1, nums2) + (nums1[i] * nums2[j])});

        return ret;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0,0, nums1, nums2);
    }
};