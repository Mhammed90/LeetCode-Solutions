class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn=1e9;

        for (int i : nums) {

            int sum = 0;
            while (i) {
                sum += i % 10;
                i /= 10;
            }
            mn = min(mn, sum);
        }

        return mn;
    }
};