class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int idx = 0;
        while (idx < n) {
            if (idx == n - 1) {
                if (!bits[idx]) {
                    return true;
                } else
                    return false;
            }
            if (!bits[idx])
                idx++;
            else {
                idx += 2;
            }
        }
        return false;
    }
};