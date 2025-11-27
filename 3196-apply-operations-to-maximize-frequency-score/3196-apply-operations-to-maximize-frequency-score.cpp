class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefx(n + 5);
        for (int i = 0; i < n; i++) {
            prefx[i + 1] = prefx[i] + nums[i];
        }
        int ans = 0;
        int l = 1, r = n;

        while (l <= r) {
            int mid = (l + r) / 2;
            int ok = 0;
            for (int i = 0; i < n; i++) {
                int L = i + 1, R = i + mid;
                if (R <= n) {
                    long long idxMid = (R + L) / 2;
                    long long medina = nums[idxMid-1];
                    long long costR =
                        (prefx[R] - prefx[idxMid - 1]) - (R - idxMid) * medina;
                    long long costL = ((idxMid - L) * medina) -
                                      (prefx[idxMid] - prefx[L - 1]);

                    //                          {1, 2, 4, 4, 4}
                    if (costL + costR <= k) {
                        //                        cout << L << " " << idxMid <<
                        //                        " " << R << " " << medina << "
                        //                        " << costL << " " << costR <<
                        //                        endl;
                        ok = 1;
                        break;
                    }

                } else
                    break;
            }
            if (ok) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};