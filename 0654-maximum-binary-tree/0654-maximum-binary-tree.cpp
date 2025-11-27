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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> res;
        for (int i = 0; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!res.empty() && res.back()->val < nums[i]) {
                cur->left = res.back();
                res.pop_back();
            }
            if (!res.empty())
                res.back()->right = cur;
            res.push_back(cur);
        }
        return res.front();
    }
};