/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        ans[0].push_back(1);

        for(int i = 1;i<numRows;++i){
            ans[i].resize(i+1);
            ans[i][0] = 1;
            ans[i][i] = 1;
            for(int j = 1;j<i;++j){
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }

        return ans;
    }
};
// @lc code=end

