class Solution {
public:
    int Spf[1005];
    void SPF() {
        int N = 1001;
        for (int i = 1; i < N; i++)
            Spf[i] = i;
        for (int i = 2; i <= N; i++) {
            for (int j = i + i; j <= N; j += i) {
                if (Spf[j] != j)
                    continue;
                Spf[j] = i;
            }
        }
    }
    bool freq[1005];
    int distinctPrimeFactors(vector<int>& nums) {
        SPF();
        int ans = 0;
        for (int i : nums) {
            while (Spf[i] != 1) {
                if (freq[Spf[i]] == 0)
                    ans++;
                freq[Spf[i]] = 1;
                i /= Spf[i];
            }
        }
        return ans;
    }
};