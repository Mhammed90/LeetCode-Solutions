class Solution {
public:
    int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
    int Spf[1000005];

    void SPF() {
        for (int i = 1; i < 1000005; i++)
            Spf[i] = i;
        for (long long i = 2; i < 1000005; i++) {
            if (Spf[i] != i)
                continue;
            for (long long j = i + i; j < 1000005; j += i) {
                if (Spf[j] != j)
                    continue;
                Spf[j] = i;
                // SPF[j]=min(SPF[j],(int)i);
            }
        }
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int gc = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            gc = gcd(gc, nums[i]);
            cnt += nums[i] == 1;
        }
        int ans = -1;
        if (gc != 1) {
            ans = -1;
        } else {
            ans = n * 2;
            if (cnt)
                return ans = n - cnt;
            for (int i = 0; i < n; i++) {
                gc = nums[i];
                cnt = gc != 1;
                for (int j = i - 1; j >= 0; j--) {
                    gc = gcd(gc, nums[j]);
                    if (gc == 1)  {       
                        ans = min(ans, i-j+n-1);
                        break;
                    }
                    cnt++;
                }
            }
        }
        return ans;
    }
};