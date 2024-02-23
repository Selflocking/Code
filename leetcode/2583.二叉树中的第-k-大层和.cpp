/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
 */
#include <vector>
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
#include <functional>
class Solution {
    vector<long long> sums{-1};
    void next(TreeNode *root, int depth) {
        if (root == nullptr) return;

        if (sums.size() <= depth) {
            sums.push_back(root->val);
        } else {
            sums[depth] += root->val;
        }

        next(root->left, depth + 1);
        next(root->right, depth + 1);
    }

  public:
    long long kthLargestLevelSum(TreeNode *root, int k) {
        next(root, 1);
        std::sort(sums.begin() + 1, sums.end(), std::greater<long long>());

        if (sums.size() <= k) {
            return -1;
        } else {
            return sums[k];
        }
    }
};
// @lc code=end
