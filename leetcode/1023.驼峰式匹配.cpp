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
        for (int x = 0; x < n; ++x) {
            int i = 0;
            int j = 0;
            while (j < pattern.size()) {
                if (queries[x][i] == pattern[j]) {
                    i++;
                    j++;
                } else {
                    if (isupper(queries[x][i])) {
                        res[x] = false;
                        break;
                    } else {
                        i++;
                    }
                }
            }
            i++;
            while (i < queries[x].size()) {
                if (isupper(queries[x][i])) {
                    res[x] = false;
                    break;
                }
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
