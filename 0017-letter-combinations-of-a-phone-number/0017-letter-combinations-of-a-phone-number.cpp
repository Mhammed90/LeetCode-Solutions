class Solution {
public:
    string arr[10] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string dig;

    void bkt(int i, string cur) {
        if (i == dig.size()) {
            res.push_back(cur);
            return;
        }

        for (auto c : arr[dig[i] - '2']) {
            cur += c;
            bkt(i + 1, cur);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        dig = digits;
        bkt(0, "");
        return res;
    }
};