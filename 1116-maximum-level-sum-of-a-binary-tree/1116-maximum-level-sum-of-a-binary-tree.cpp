class Solution {
public:
    int SUM[100005];
    int mx = INT_MIN, idx = 0,LEVEL=0;

    void solve(TreeNode* node, int lev) {
        if (!node) return;
      LEVEL=max(LEVEL,lev);
        SUM[lev] += node->val;
        solve(node->left, lev + 1);
        solve(node->right, lev + 1);
    }

    int maxLevelSum(TreeNode* root) {
        solve(root, 0);

        for (int i = 0; i <=LEVEL; i++) {
            if (SUM[i] > mx) {
                mx = SUM[i];
                idx = i;
            }
        }
        return idx + 1;
    }
};
