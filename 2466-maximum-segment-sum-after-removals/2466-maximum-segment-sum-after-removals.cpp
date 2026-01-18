long long INF = -1000000000000000;
class Solution {
public:
    struct Node {
        long long mx, sum, sufx, prfix;

        Node() {
            mx = 0;
            sum = sufx = prfix = 0;
        }

        Node(long long x) { mx = sum = prfix = sufx = x; }

        void change(long long x) { mx = sum = prfix = sufx = x; }
    };

    struct SegTree {
        int treeSize;
        vector<Node> SegData;

        SegTree(int n) {
            treeSize = 1;
            while (treeSize < n)
                treeSize *= 2;
            SegData.assign(2 * treeSize, Node()); // assign neutral node
        }

        Node merge(Node& lf, Node& ri) {
            Node ans = Node();
            ans.mx = max(INF, max({lf.mx, ri.mx, lf.sufx + ri.prfix}));
            ans.sufx = max(INF, max(ri.sufx, ri.sum + lf.sufx));
            ans.prfix = max(INF, max(lf.prfix, lf.sum + ri.prfix));
            ans.sum = max(INF, lf.sum + ri.sum);
            return ans;
        }

        void set(int idx, long long val, int ni, int lx, int rx) // 0-Indexed
        {
            if (rx - lx == 1) {
                SegData[ni].change(val);
                return;
            }
            int mid = (rx + lx) / 2;
            if (idx < mid)
                set(idx, val, 2 * ni + 1, lx, mid);
            else
                set(idx, val, 2 * ni + 2, mid, rx);
            // merge after update
            SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
        }

        void set(int idx, long long val) { set(idx, val, 0, 0, treeSize); }
    };

    vector<long long> maximumSegmentSum(vector<int>& nums,
                                        vector<int>& removeQueries) {

        int n = nums.size();
        SegTree seg(n + 5);
        for (int i = 0; i < n; i++) {
            seg.set(i, nums[i]);
        }
        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            seg.set(removeQueries[i], INF);
            ans[i] = max(seg.SegData[0].mx, 0LL);
        }
        return ans;
    }
};