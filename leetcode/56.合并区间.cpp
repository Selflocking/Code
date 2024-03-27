/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        const int n = intervals.size();
        if (n <= 1) return intervals;

        vector<vector<int>> res;

        std::sort(intervals.begin(), intervals.end(),
                  [](vector<int> &a, vector<int> &b) {
                      if (a[0] != b[0]) {
                          return a[0] < b[0];
                      } else {
                          return a[1] < b[1];
                      }
                  });

        // 使用栈的思想
        vector<int> stack = intervals[0];
        for (int i = 1; i < n; ++i) {
            auto &item = intervals[i];

            if (item[0] == stack[0]) {
                stack[1] = max(stack[1], item[1]);
            } else if (item[0] > stack[1]) {
                res.push_back(stack);
                stack = item;
            } else {
                // item[0] <= stack[1]
                stack[1] = max(stack[1], item[1]);
            }
        }
        res.push_back(stack);
        return res;
    }
};
// @lc code=end
