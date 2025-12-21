
class Solution {
public:
    struct DSU {
        vector<int> Parent, GroupSize;
        int numOfGroups;

        DSU(int n) {
            numOfGroups = n;
            Parent.resize(n + 2);
            GroupSize.resize(n + 2);
            for (int i = 0; i <= n; i++) {
                Parent[i] = i;
                GroupSize[i] = 1;
            }
        }

        int getParent(int u) {
            if (Parent[u] == u)
                return u;
            return Parent[u] = getParent(Parent[u]);
        }

        void merge(int u, int v) {
            int par1 = getParent(u);
            int par2 = getParent(v);
            if (par1 == par2) {
                return;
            }
            numOfGroups--;
            if (GroupSize[par1] > GroupSize[par2]) {
                Parent[par2] = par1;
                GroupSize[par1] += GroupSize[par2];
            } else {
                Parent[par1] = par2;
                GroupSize[par2] += GroupSize[par1];
            }
        }

        bool sameGroup(int u, int v) {
            int par1 = getParent(u);
            int par2 = getParent(v);
            return par2 == par1;
        }

        int getGroupSize(int u) {
            int par = getParent(u);
            return GroupSize[par];
        }
    };

    int SPF[100005];

    void buildSpf() {
        for (int i = 1; i <= 100000; i++)
            SPF[i] = i;
        for (int i = 2; i <= 100000; i++) {
            if (SPF[i] == i) {
                for (int j = i + i; j <= 100000; j += i) {
                    SPF[j] = i;
                }
            }
        }
    }

    int largestComponentSize(vector<int>& nums) {
        buildSpf();
        DSU ds(100006);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            while (SPF[cur] != 1) {
                ds.merge(nums[i], SPF[cur]);
                cur /= SPF[cur];
            }
        }
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int p = ds.getParent(nums[i]);
            mp[p]++;
            ans = max(ans, mp[p]);
        }
        return ans;
    }
};