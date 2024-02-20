/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        int md = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                md = i;
                break;
            }
        }
        vector<int> fpreorder, finorder;
        for (int i = 0; i < md; ++i) {
            finorder.push_back(inorder[i]);
            fpreorder.push_back(preorder[i + 1]);
        }
        root->left = buildTree(fpreorder, finorder);

        vector<int> bpreorder, binorder;
        for (int i = md + 1; i < inorder.size(); ++i) {
            binorder.push_back(inorder[i]);
            bpreorder.push_back(preorder[i]);
        }
        root->right = buildTree(bpreorder, binorder);
        return root;
    }
};
// @lc code=end
