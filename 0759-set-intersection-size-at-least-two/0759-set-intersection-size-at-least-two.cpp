

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1])
                     return a[0] > b[0];
                 return a[1] < b[1];
             });

        set<int> res;
        int ans = 0;

        for (auto i : intervals) {
            int start = i[0];
            int end = i[1];

            int count = 0;
            for (int x : res)
                if (x >= start && x <= end)
                    count++;

            if (count >= 2)
                continue;
            else if (count == 1) {
                res.insert(end);
                ans += 1;
            } else {
                res.insert(end - 1);
                res.insert(end);
                ans += 2;
            }
        }

        return res.size();
    }
};
