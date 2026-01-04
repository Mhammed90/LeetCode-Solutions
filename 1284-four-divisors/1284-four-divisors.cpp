class Solution {
public:
    int Freq[1000005];
    int SUM [1000005];

    void pre() {
        int N = 1000001;
        for (int i = 1; i < N; i++) {
            for (int j = i; j < N; j += i) {
                Freq[j]++; 
                SUM[j] += i;
            }
        }
    }

    int sumFourDivisors(vector<int> &nums) {
        pre();
        int ans = 0;
        for (int i: nums) {
         if(Freq[i]==4)ans+=SUM[i];
        }

        return ans;
    }
};