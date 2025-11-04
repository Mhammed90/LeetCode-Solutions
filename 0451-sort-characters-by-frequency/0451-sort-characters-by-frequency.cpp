class Solution {
public:
    string frequencySort(string s) {
        map<char, int> Freq;
        for (auto i : s) {
            Freq[i]++;
        }
        vector<pair<int, char>> comp;
        for (auto i : Freq)
            comp.push_back({i.second, i.first});

        sort(comp.begin(), comp.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });

        string res = "";
        for (auto i : comp) {
            int cnt = i.first;
            while (cnt--)
                res += i.second;
        }
        return res;
    }
};