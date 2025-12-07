class Solution {
public:
    const long long m1 = 1000000033, m2 = 1000000039, m3 = 1000000237,
                    m4 = 1000000367;

    struct HashedString {
        long long M;
        long long B;

        vector<long long> pow;

        vector<long long> p_hash;

        HashedString(const vector<int>& s, const int Mod, int Base)
            : p_hash(s.size() + 1), M(Mod), B(Base) {
            pow.push_back(1);
            while (pow.size() <= s.size()) {
                pow.push_back((pow.back() * B) % M);
            }
            p_hash[0] = 0;
            for (int i = 0; i < s.size(); i++) {
                p_hash[i + 1] = ((p_hash[i] * B) % M + (s[i])) % M;
            }
        }

        long long getRange(int start, int end) {
            long long raw_val =
                (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
            return (raw_val % M + M) % M;
        }
    };

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {

        int n = nums.size(), m = pattern.size();
        vector<int> temp(n);
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] < nums[i + 1])
                temp[i] = 1;
            else if (nums[i] > nums[i + 1])
                temp[i] = -1;
            else
                temp[i] = 0;
            temp[i] += 2;
        }
        for (int& i : pattern)
            i += 2;
        HashedString h1(temp, m1, 67);
        HashedString h2(pattern, m1, 67);
        int ans = 0;
        int g2 = h2.getRange(0, m - 1);
        for (int i = 0; i < n; i++) {
            if (i + m < n) {
                int g1 = h1.getRange(i, i + m - 1);
                ans += (g1 == g2);
            }
        }
        return ans;
    }
};
