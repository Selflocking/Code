/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();

        vector<int> lh(n);
        int lm = 0;
        for(int i = 0;i<n;++i){
            lm = max(lm,height[i]);
            lh[i] = lm - height[i];
        }

        vector<int> rh(n);
        int rm = 0;
        for(int i = n-1;i>=0;--i){
            rm = max(rm,height[i]);
            rh[i] = rm-height[i];
        }

        int ans = 0;
        for(int i = 0;i<n;++i){
            ans += min(lh[i],rh[i]);
        }
        return ans;
    }
};
// @lc code=end

