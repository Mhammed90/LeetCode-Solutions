class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        char ans = '0';
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target < letters[mid])
                ans = letters[mid], r = mid - 1;
            else
                l = mid + 1;
        }
        if (ans == '0')
            return letters[0];
        return ans;
    }
};