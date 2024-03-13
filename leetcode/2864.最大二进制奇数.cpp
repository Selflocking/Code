/*
 * @lc app=leetcode.cn id=2864 lang=cpp
 *
 * [2864] 最大二进制奇数
 */

// @lc code=start
class Solution {
  public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        int zero = 0;
        for (auto c : s) {
            if (c == '1') {
                one++;
            } else {
                zero++;
            }
        }

        string res;
        while (zero + one > 0) {
            if (one > 1) {
                res += '1';
                one--;
            } else if (zero > 0) {
                res += '0';
                zero--;
            } else {
                res += '1';
                one--;
            }
        }
        return res;
    }
};
// @lc code=end
