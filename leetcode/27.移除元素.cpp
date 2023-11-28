/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] == val) {
                nums[i] = nums[size - 1];
                size--;
                i--;
            }
        }
        return size;
    }
};
// @lc code=end
