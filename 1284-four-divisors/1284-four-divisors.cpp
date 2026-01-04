class Solution {
public:
    int SPF[1000005];

    void spf() {
        int N = 1000001;
        for (int i = 0; i < N; i++)
            SPF[i] = i;
        for (int i = 2; i < N; i++)
            SPF[i] = i;
        for (int i = 2; i < N; i++) {
            if (SPF[i] != i)
                continue;
            for (int j = i + i; j < N; j += i) {
                if (SPF[j] != j)
                    continue;
                SPF[j] = i;
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        spf();
        int ans = 0;
        for (int i : nums) {
            int d = SPF[i];
            if (1LL * d * d == i || SPF[i] == i)
                continue;
            if (1LL * d * d * d == i) {
                ans += 1 + d + d * d + i;
                continue;
            }
            int sum = i + 1;
            sum += d;
            i /= SPF[d];
            if (SPF[i] == i) {
                sum += i;
                ans += sum;
            }
        }

        return ans;
    }
};