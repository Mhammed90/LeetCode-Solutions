
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++) {
            while (arr1[i]) {
                mp[arr1[i]] = true;
                arr1[i] /= 10;
            }
        }
        n = arr2.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (arr2[i] && mp.find(arr2[i]) == mp.end()) {
                arr2[i] /= 10;
            }
            if (arr2[i]) {
                int cnt = 0;
                while (arr2[i]) {
                    arr2[i] /= 10;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};