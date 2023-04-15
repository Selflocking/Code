/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector<int> res(n, 0);
        vector<vector<int>> G(n);
        for (auto &i : paths) {
            G[max(i[1] - 1, i[0] - 1)].emplace_back(min(i[0] - 1, i[1] - 1));
        }
        vector<bool> st(5, false);
        for (int i = 0; i < n; ++i) {
            for (auto &ed : G[i]) {
                st[res[ed]] = true;
            }
            for (int j = 1; j <= 4; ++j) {
                if (!st[j]) {
                    res[i] = j;
                    break;
                }
            }
            fill(st.begin(), st.end(), false);
        }
        return res;
    }
};
// @lc code=end
