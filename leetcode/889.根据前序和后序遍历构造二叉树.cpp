/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// @lc code=start
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
    TreeNode *constructFromPrePost(vector<int> &preorder,
                                   vector<int> &postorder) {
        if (preorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        if (preorder.size() == 1) return root;

        int fd = 0;
        for (int i = 0; i < postorder.size(); ++i) {
            if (postorder[i] == preorder[1]) {
                fd = i;
            }
        }

        vector<int> fpre, fpost;
        for (int i = 0; i <= fd; ++i) {
            fpost.push_back(postorder[i]);
            fpre.push_back(preorder[i + 1]);
        }

        root->left = constructFromPrePost(fpre, fpost);

        vector<int> bpre, bpost;
        for (int i = fd + 1; i < postorder.size() - 1; ++i) {
            bpost.push_back(postorder[i]);
            bpre.push_back(preorder[i + 1]);
        }
        root->right = constructFromPrePost(bpre, bpost);

        return root;
    }
};
// @lc code=end
