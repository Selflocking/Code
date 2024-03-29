/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        const int n = nums.size();
        if (n <= 1) return;
        k = k % n;

        vector<int> arr;
        for (int i = n - k; i < n; ++i) {
            arr.push_back(nums[i]);
        }
        for (int i = n - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = arr[i];
        }
    }
};
// @lc code=end
int main() {
    Solution s;
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums, k);

    return 0;
}