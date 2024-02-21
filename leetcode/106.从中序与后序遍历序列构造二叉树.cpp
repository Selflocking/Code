/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

#include <vector>

using std::vector;
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(postorder.back());

        int mid = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == postorder.back()) {
                mid = i;
                break;
            }
        }

        vector<int> finorder, fpostorder;
        for (int i = 0; i < mid; ++i) {
            finorder.push_back(inorder[i]);
            fpostorder.push_back(postorder[i]);
        }

        root->left = buildTree(finorder, fpostorder);

        vector<int> binorder, bpostorder;
        for (int i = mid + 1; i < inorder.size(); ++i) {
            binorder.push_back(inorder[i]);
            bpostorder.push_back(postorder[i - 1]);
        }

        root->right = buildTree(binorder, bpostorder);

        return root;
    }
};
// @lc code=end
