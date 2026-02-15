class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int cur = a[i] - '0' + b[j] - '0' + carry;
            if (cur > 1) { 

                res +=( (cur%2)+'0');
                carry = 1;
            } else {
                res += ('0' + cur);
                carry = 0;
            }
            i--, j--;
        }

        while (i >= 0) {
            int cur = a[i] - '0' + carry;

            if (cur > 1)
                res += '0', carry = 1;
            else
                res += ('0' + cur), carry = 0;
            i--;
        }
        while (j >= 0) {
            int cur = b[j] - '0' + carry;
            if (cur > 1)
                res += '0', carry = 1;
            else
                res += ('0' + cur), carry = 0;
            j--;
        }
        if (carry)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};