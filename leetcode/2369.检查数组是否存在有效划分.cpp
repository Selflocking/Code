/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 */

#include <csignal>
#include <cstddef>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    bool dfs(const vector<int> &nums, int n) {
        // 如果刚好分配完
        if (n == -1) return true;
        // 如果仅剩一个数, 或者非法 n
        if (n <= 0) return false;

        /*
            在后两个数相等的情况下看前n-2个数是否满足
            在后三个数相等的情况下看前n-3个数是否满足
            在后三个数连续的情况下看前n-3各数是否满足
        */
        if (nums[n] == nums[n - 1]) {
            bool ok = dfs(nums, n - 2);

            if (!ok && nums[n - 1] == nums[n - 2]) {
                ok = dfs(nums, n - 3);
            }
            return ok;
        }

        if (n >= 2 && nums[n] == nums[n - 1] + 1 &&
            nums[n] == nums[n - 2] + 2) {
            return dfs(nums, n - 3);
        }

        // 既不相等又不连续
        return false;
    }

    // 会超时
    bool dfs2(const vector<int> &nums, int n) {
        // 如果刚好分配完
        if (n == -1) return true;
        // 如果仅剩一个数, 或者非法 n
        if (n <= 0) return false;

        /*
        在前n-2个数满足的情况下看后两个数是否相等
        在前n-3各数满足的情况下看后三个数是否相等或者连续
        */
        if (dfs2(nums, n - 2)) {
            if (nums[n] == nums[n - 1]) {
                return true;
            }
        }

        if (n >= 2 && dfs2(nums, n - 3)) {
            if ((nums[n] == nums[n - 1] && nums[n] == nums[n - 2]) ||
                (nums[n] == nums[n - 1] + 1 && nums[n] == nums[n - 2] + 2)) {
                return true;
            }
        }

        // 前n-2或前n-3都不满足,
        // 或者后两个不相等，或这后三个不相等，或后三个不连续
        return false;
    }

    // 动态规划， 参照dfs2
    bool solve(const vector<int> &nums) {
        const int n = nums.size();
        vector<bool> f(n + 1, false);
        f[0] = true;
        // f[i] 代表是否能划分 nums[0, i)
        // 即f[n] 代表 nums[0, n);
        for (int i = 1; i < n; ++i) {
            if (f[i - 2 + 1]) {
                f[i + 1] = nums[i] == nums[i - 1];
            }
            if (i >= 2 && f[i - 3 + 1]) {
                f[i + 1] =
                    f[i + 1] ||
                    (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ||
                    (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2);
            }
        }

        return f[n];
    }

  public:
    bool validPartition(vector<int> &nums) {
        // return dfs(nums, nums.size() - 1);
        // return dfs2(nums, nums.size() - 1);
        return solve(nums);
    };
};
// @lc code=end
