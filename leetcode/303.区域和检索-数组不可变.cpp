/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    vector<int> sum{0};

  public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) return;

        sum.push_back(nums.front());
        const int n = nums.size();
        for (int i = 1; i < n; ++i) {
            sum.push_back(sum.back() + nums[i]);
        }
    }

    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
