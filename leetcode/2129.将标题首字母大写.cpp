/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */

// @lc code=start
class Solution {
  public:
    string capitalizeTitle(string title) {
        const int n = title.size();

        size_t l = 0;
        size_t r = 0;
        while (r < n) {
            while (r < n && title[r] != ' ') {
                r++;
            }

            if (r - l > 2) {
                title[l] = toupper(title[l]);
                l++;
            }
            while (l < r) {
                title[l] = tolower(title[l]);
                l++;
            }
            r++;
            l = r;
        }
        return title;
    }
};
// @lc code=end
