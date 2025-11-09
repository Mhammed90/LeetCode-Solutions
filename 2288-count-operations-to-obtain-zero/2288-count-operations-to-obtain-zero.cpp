class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        if (num1 < num2)
            swap(num1, num2);
        while (num2) {
            num1 -= num2;
            ans++;
            if (num1 < num2)
                swap(num1, num2);
        }
        return ans;
    }
};