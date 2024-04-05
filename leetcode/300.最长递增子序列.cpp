/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n+1);
        f[0] = 1;
        int ans = 0;
        for(int i = 1;i<=n;++i){
            f[i] = 1;
            for(int j = 1;j<i;++j){
                if(nums[j-1]<nums[i-1]){
                    f[i] = max(f[i],f[j]+1);
                }
            }
            ans = max(ans,f[i]);
        }
        return ans;
    }
};
// @lc code=end

