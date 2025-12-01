class Solution {
public:
    int minLength(string s) {
        string res;

        for (char i : s) {
            if (res.size() && ((res.back() == 'A' && i == 'B') ||
                               (res.back() == 'C' && i == 'D')))
                res.pop_back();
            else
                res += i;
        }
        return res.size();
    }
};