/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* node, int val) {
        if (node == NULL)
            return 0; 
            //leaf
        if (node->left == NULL && node->right == NULL) {
            return val * 2 + node->val;
        }
        int left = sum(node->left, val * 2 + node->val);
        int right = sum(node->right, val * 2 + node->val);
        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) { return sum(root, 0); }
};