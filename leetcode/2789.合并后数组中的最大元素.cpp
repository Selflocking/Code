/*
 * @lc app=leetcode.cn id=2789 lang=cpp
 *
 * [2789] 合并后数组中的最大元素
 */

// @lc code=start
#include <cstddef>
class Solution {
  public:
    long long maxArrayValue(vector<int> &nums) {
        long long ans = 0;
        const size_t n = nums.size();
        long long sum = nums[n - 1];
        for (int i = n - 1; i > 0; --i) {
            if (sum >= nums[i - 1]) {
                sum += nums[i - 1];
            } else {
                // useless
                // ans = max(ans, sum);
                sum = nums[i - 1];
            }
        }
        // useless
        // ans = max(ans, sum);
        return sum;
    }
};
// @lc code=end
