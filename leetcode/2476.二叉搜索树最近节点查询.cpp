/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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
#include <algorithm>
#include <cstddef>
class Solution {
    vector<int> tree;

    void build(TreeNode *root) {
        if (root == nullptr) return;

        build(root->left);
        tree.push_back(root->val);
        build(root->right);
    }

  public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        build(root);

        vector<vector<int>> ans;
        for (auto x : queries) {
            auto it = std::upper_bound(tree.begin(), tree.end(), x);

            int mi = -1;
            int mx = -1;
            if (it == tree.begin()) {
                // 如果全是大于x的
                mx = *it;
                mi = -1;
            } else if (*(it - 1) == x) {
                // 先判断上一位是不是x
                mi = mx = x;
            } else if (it == tree.end()) {
                // 上一位不是x,故全是小于x的
                mi = tree.back();
                mx = -1;
            } else {
                // 二分结果在中间
                mx = *it;
                mi = *(it - 1);
            }

            ans.push_back({mi, mx});
        }
        return ans;
    }
};
// @lc code=end
