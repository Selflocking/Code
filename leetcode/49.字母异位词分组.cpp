/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
// TODO: 考虑更优的解法
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;
// @lc code=start
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, size_t> hashtable;

        const size_t n = strs.size();
        size_t cnt = 0;
        vector<vector<string>> res;
        for (size_t i = 0; i < n; ++i) {
            auto str = strs[i];
            std::sort(str.begin(), str.end());

            auto it = hashtable.find(str);
            if (it == hashtable.end()) {
                res.push_back({});
                res[cnt].push_back(strs[i]);
                hashtable[str] = cnt;

                cnt++;
            } else {
                auto l = it->second;
                res[l].push_back(strs[i]);
            }
        }

        return res;
    }
};
// @lc code=end
