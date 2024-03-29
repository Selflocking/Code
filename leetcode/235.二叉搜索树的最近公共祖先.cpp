/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        int mx = max(p->val, q->val);
        int mi = min(p->val, q->val);

        while (root != nullptr) {
            if (root->val > mx) {
                root = root->left;
            } else if (root->val < mi) {
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
};
// @lc code=end
