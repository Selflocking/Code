/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0];
        int min_pre_sum = 0;
        int pre_sum = 0;
        for(int i = 0;i<n;++i){
            pre_sum = pre_sum + nums[i];
            ans = max(ans,pre_sum-min_pre_sum);
            min_pre_sum = min(min_pre_sum,pre_sum);
        }
        return ans;
    }
};
// @lc code=end

