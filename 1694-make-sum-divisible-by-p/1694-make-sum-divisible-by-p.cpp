class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        map<int, vector<int>> mp;
        int sum = 0;
        long long sumTot = 0;
        int ans = n;
        for (int i = 0; i < n; i++) {
            sumTot += nums[i];
            mp[sumTot % p].push_back(i);
            if (sumTot % p == 0)
                ans = min(ans, n - i - 1);
        }
        if (sumTot % p == 0)
            return 0;
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            sum %= p;
            if (sum == 0)
                ans = min(ans, i);
            int remind = (p - sum)%p;
            mp[sumTot % p].pop_back();
            cout << sum << " " << remind << endl;
            if (mp.count(remind)) {
                if (mp[remind].size())
                    ans = min(ans, i - mp[remind].back() - 1);
            }
            sumTot -= nums[i];
        } 
        if(ans==n)ans=-1;
        return ans;
    }
};