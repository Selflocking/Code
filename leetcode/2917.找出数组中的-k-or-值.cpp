/*
 * @lc app=leetcode.cn id=2917 lang=cpp
 *
 * [2917] 找出数组中的 K-or 值
 */

// @lc code=start
class Solution {
  public:
    int findKOr(vector<int> &nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int cnt = 0;
            for (auto x : nums) {
                cnt += x >> i & 1;
            }
            if (cnt >= k) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};
// @lc code=end
