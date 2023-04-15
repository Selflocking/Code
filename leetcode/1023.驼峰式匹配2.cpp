/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        vector<bool> res(queries.size(), true);
        const int n = queries.size();
        const int pn = pattern.size();
        for (int x = 0; x < n; ++x) {
            int i = 0;
            for (auto c : queries[x]) {
                if (i < pn && c == pattern[i]) {
                    i++;
                } else if (isupper(c)) {
                    res[x] = false;
                    break;
                }
            }
            if (i != pn) res[x] = false;
        }
        return res;
    }
};
// @lc code=end
