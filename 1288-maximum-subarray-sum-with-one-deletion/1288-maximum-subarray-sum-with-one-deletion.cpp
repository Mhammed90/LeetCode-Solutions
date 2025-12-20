class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        vector<int> prefx(n), suffx(n);
        prefx[0] = arr[0];
        suffx[n - 1] = arr[n - 1];
        int ans = -1e9;
        int mxPrefx = arr[0];
        for (int i = 1; i < n; i++) {
            prefx[i] = max(prefx[i - 1] + arr[i], arr[i]);
            mxPrefx = max(mxPrefx, prefx[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffx[i] = max(suffx[i + 1] + arr[i], arr[i]);
        }
        ans = mxPrefx;
        for (int i = 1; i + 1 < n; i++) {
            // remove this
            ans = max(ans, suffx[i + 1] + prefx[i - 1]);
        }

        return ans;
    }
};