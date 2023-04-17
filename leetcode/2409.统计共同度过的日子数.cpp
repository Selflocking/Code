/*
 * @lc app=leetcode.cn id=2409 lang=cpp
 *
 * [2409] 统计共同度过的日子数
 */
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

// @lc code=start
class Solution {
  public:
    int m[13] = {0, 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        for (int i = 1; i < 13; ++i) {
            m[i] += m[i - 1];
        }
        int a = 0, b = 0;
        sscanf(arriveAlice.c_str(), "%d-%d", &a, &b);
        int aa = m[a] + b;
        sscanf(leaveAlice.c_str(), "%d-%d", &a, &b);
        int la = m[a] + b;
        sscanf(arriveBob.c_str(), "%d-%d", &a, &b);
        int ab = m[a] + b;
        sscanf(leaveBob.c_str(), "%d-%d", &a, &b);
        int lb = m[a] + b;
        return max(0, min(la, lb) - max(aa, ab) + 1);
    }
};
// @lc code=end
