/*
 * @lc app=leetcode.cn id=3174 lang=cpp
 *
 * [3174] 清除数字
 */

// @lc code=start
class Solution {
  public:
    string clearDigits(string s) {
        string res;
        for (auto c : s) {
            if (isdigit(c)) {
                res.pop_back();
            } else {
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end
