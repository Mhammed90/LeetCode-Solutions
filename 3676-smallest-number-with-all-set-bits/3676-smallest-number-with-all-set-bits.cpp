class Solution {
public:
    int smallestNumber(int n) {
        int lg = log2(n) + 1;
        return (1 << lg) - 1;
    }
};