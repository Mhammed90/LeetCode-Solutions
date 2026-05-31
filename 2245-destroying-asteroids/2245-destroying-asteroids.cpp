class Solution {
public:
    int freq[100005];
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum = mass;
        int mx = 0;
        for (int i : asteroids) {
            freq[i]++;
            mx = max(mx, i);
        }

        for (int i = 1; i <= mx; i++) {
            if (freq[i]) {
                if (i > sum)
                    return 0;
                sum += (1LL * i * freq[i]);
            }
        }

        return 1;
    }
};