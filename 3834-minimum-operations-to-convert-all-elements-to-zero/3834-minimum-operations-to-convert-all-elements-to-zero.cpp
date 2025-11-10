
class segTree {

private:
    struct Node {
        int val;

        Node() { val = 100005; }

        Node(int x) { val = x; }

        void change(int x) { val = x; }
    };

    Node merge(Node& lf, Node& ri) {
        Node ans = Node();
        ans.val = min(lf.val, ri.val);
        return ans;
    }

    void set(int idx, int val, int ni, int lx, int rx) // 0-Indexed
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

    Node get(int l, int r, int ni, int lx, int rx) // 0-Indexed
    {
        if (r >= rx && l <= lx)
            return SegData[ni];
        if (lx >= r || rx <= l)
            return Node();
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }

    void build(vector<int>& arr, int no, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size())
                SegData[no] = Node(arr[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(arr, 2 * no + 1, lx, mid);
        build(arr, 2 * no + 2, mid, rx);
        SegData[no] = merge(SegData[2 * no + 1], SegData[2 * no + 2]);
    }

public:
    int sz;
    vector<Node> SegData;

    segTree(int n) {
        sz = 1;
        while (sz <= n)
            sz *= 2;
        SegData.assign(2 * sz, Node());
    }

    void set(int idx, int val) { set(idx, val, 0, 0, sz); }

    void build(vector<int>& arr) { build(arr, 0, 0, sz); }

    int get(int l, int r) { return get(l, r, 0, 0, sz).val; }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> adj[100005];
        adj[nums[0]].push_back(0);
        int mx = nums[0];
        vector<int> temp = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {
                temp.push_back(nums[i]);
            }
            mx = max(mx, nums[i]);
        }

        int n = temp.size();
        for (int i = 1; i < n; i++) {
            adj[temp[i]].push_back(i);
        }
        int ans = 0;

        segTree seg(n);
        seg.build(temp);

        for (int i = 0; i <= mx; i++) {
            int l = -1, r = l;
            int cnt = 0;
            for (int j : adj[i]) {
                cnt++;
                if (l == -1) {
                    l = j;
                } else
                    r = j;
                if (min(l, r) != -1) {
                    int g = seg.get(l, r + 1);
                    if (g < i) {
                        l = r, r = -1;
                        if (cnt)
                            ans++;
                        cnt = 1;
                 }
                }
            }
            if (i && l != -1) {
                ans++;
            }
            for (int j : adj[i]) {
                seg.set(j, 0);
            }
        }
        return ans;
    }
};
