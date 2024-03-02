/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
 */
#include <set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
    int ans = 1;
    vector<vector<int>> paths;

    void dfs(int x, int f) {
        for (auto i : paths[x]) {
            if (i != f) {
                ans++;
                dfs(i, x);
            }
        }
    }

  public:
    int reachableNodes(int n, vector<vector<int>> &edges,
                       vector<int> &restricted) {
        set<int> s(restricted.begin(), restricted.end());
        paths.resize(n);
        for (auto &edge : edges) {
            auto a = edge[0];
            auto b = edge[1];

            if (!s.count(a) && !s.count(b)) {
                paths[a].push_back(b);
                paths[b].push_back(a);
            }
        }

        dfs(0, -1);
        return ans;
    }
};
// @lc code=end
