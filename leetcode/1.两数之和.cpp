/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <cstddef>
#include <unordered_map>
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int, int> m;
        const size_t n = nums.size();
        for (size_t i = 0; i < n; ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                return {it->second, static_cast<int>(i)};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
