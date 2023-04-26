/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        const int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + firstLen + secondLen - 1; j <= n; ++j) {
                int totalSum = sum[j] - sum[i - 1];
                // first 在前
                int t1 =
                    totalSum - (sum[j - secondLen] - sum[i + firstLen - 1]);
                // second 在前
                int t2 =
                    totalSum - (sum[j - firstLen] - sum[i + secondLen - 1]);
                res = max(res, max(t1, t2));
            }
        }
        return res;
    }
};
// @lc code=end
