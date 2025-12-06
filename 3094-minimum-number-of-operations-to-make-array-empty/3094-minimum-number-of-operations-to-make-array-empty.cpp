class Solution {
public:
    int freq[1000005];
    int minOperations(vector<int>& nums) {
        int mx = 0;
        for (int i : nums) {
            freq[i]++;
            mx = max(mx, i);
        }
        int ans = 0;
        for (int i = 0; i <= mx; i++) {
            if (freq[i]) {
                if (freq[i] < 2)
                    return -1;
                if (freq[i] % 3 == 0)
                    ans += freq[i] / 3;
                else if (freq[i] % 3 == 2)
                    ans += freq[i] / 3 + 1;
                else
                    ans += (freq[i] - 2) / 3 + 2;
            }
        }
        return ans;
    }
};

/*

freq[x]%3==0
ans+=(freq[x]/3)

 if(freq[x]%3==2 )
   ans+=freq[x]/3+1;
  8
  3 3 2
  10
  3 3 2 2

  ans+=(freq[x]-2)/3+2;

 */