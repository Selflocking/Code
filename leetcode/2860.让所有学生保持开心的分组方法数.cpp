/*
 * @lc app=leetcode.cn id=2860 lang=cpp
 *
 * [2860] 让所有学生保持开心的分组方法数
 */

// @lc code=start
class Solution {
  public:
    int countWays(vector<int> &nums) {
        int res = 0;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) {
            res++;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < i + 1 && i + 1 < nums[i + 1]) {
                res++;
            }
        }
        if (nums[n - 1] < n) {
            res++;
        }
        return res;
    }
};
// @lc code=end
