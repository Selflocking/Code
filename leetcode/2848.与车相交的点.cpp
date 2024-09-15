/*
 * @lc app=leetcode.cn id=2848 lang=cpp
 *
 * [2848] 与车相交的点
 */

// @lc code=start
class Solution {
  public:
    int numberOfPoints(vector<vector<int>> &nums) {
        // 最大是100, 差分数组从1开始，下面操作用到了end+1,所以是102
        vector<int> road(102);
        for (auto n : nums) {
            int start = n[0];
            int end = n[1];
            road[start] += 1;
            road[end + 1] -= 1;
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            road[i] += road[i - 1];
            if (road[i] > 0) {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end
