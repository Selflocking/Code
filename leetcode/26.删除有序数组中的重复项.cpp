/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        const int n = nums.size();
        if (n <= 1) {
            return n;
        }

        int left = 0;
        int right = 1;
        while (right <= n - 1) {
            auto &l = nums[left];
            auto &r = nums[right];
            if (l != r) {
                nums[left + 1] = r;
                left++;
            }
            right++;
        }
        return left + 1;
    }
};
// @lc code=end
