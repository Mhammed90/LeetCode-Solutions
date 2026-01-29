class Solution {
public:
    void floydWarshall(vector<vector<long long>>& dist) {
        int sz = 26;
        for (int k = 0; k < sz; k++) {
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    if (dist[i][k] != 1e12 && dist[k][j] != 1e12)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, 1e12));
        for (int i = 0; i < original.size(); i++) {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            dist[a][b] = min(dist[a][b], 1LL * cost[i]);
        }
        floydWarshall(dist);

        long long ans = 0;
        for (int i = 0; i < target.size(); i++) {
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if (a != b) {
                if (dist[a][b] == 1e12)
                    return -1;
                ans += dist[a][b];
            }
        }
        return ans;
    }
};