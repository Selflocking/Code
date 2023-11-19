/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> nums3 = nums1;
        int i = 0; // nums3
        int j = 0;
        // 双指针
        while (i + j < m + n) {
            // 当一个数组已经被选完的情况
            if (i >= m) {
                for (; j < n; ++j) {
                    nums1[i + j] = nums2[j];
                }
                break;
            }
            if (j >= n) {
                for (; i < m; ++i) {
                    nums1[i + j] = nums3[i];
                }
                break;
            }
            // 从两个数组里面选取一个合并进结果
            if (nums3[i] < nums2[j]) {
                nums1[i + j] = nums3[i];
                i++;
            } else {
                nums1[i + j] = nums2[j];
                j++;
            }
        }
    }
};
// @lc code=end
