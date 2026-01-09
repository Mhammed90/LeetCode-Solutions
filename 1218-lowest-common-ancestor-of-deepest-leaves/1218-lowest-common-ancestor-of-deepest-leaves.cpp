class Solution {
public:
    int dep(TreeNode* node) {
        if (node == nullptr)
            return 0;
        return 1 + max(dep(node->left), dep(node->right));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        int leftDepth = dep(root->left);
        int rightDepth = dep(root->right);
        if (leftDepth == rightDepth)
            return root;
        if (leftDepth > rightDepth)
            return lcaDeepestLeaves(root->left);
        else
            return lcaDeepestLeaves(root->right);
    }
};
