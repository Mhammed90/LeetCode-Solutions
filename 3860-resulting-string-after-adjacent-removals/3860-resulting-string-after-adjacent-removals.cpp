class Solution {
public:
    string resultingString(string s) {
        string res;
        res += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (res.size() &&
                (abs(s[i] - res.back()) == 1 || abs(s[i] - res.back()) == 25)) {
                res.pop_back();
            } else
                res += s[i];
        }
        return res;
    }
};