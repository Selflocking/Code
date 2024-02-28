/*
 * @lc app=leetcode.cn id=2673 lang=cpp
 *
 * [2673] 使二叉树所有路径值相等的最小代价
 */
#include <cstdlib>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
    int ans = 0;
    int dfs(vector<int> &cost, int x) {
        if (x > cost.size()) return 0;

        int left = dfs(cost, 2 * x);
        int right = dfs(cost, 2 * x + 1);

        int diff = abs(right - left);
        int mx = max(left, right);
        ans += diff;
        return cost[x - 1] + mx;
    }

  public:
    int minIncrements(int n, vector<int> &cost) {
        dfs(cost, 1);
        return ans;
    }
};
// @lc code=end
