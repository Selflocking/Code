/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
// 从后往前处理，先去掉0,再最后补零
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int cnt = 0;
        for(int i = n-1;i>=0;--i){
            if(nums[i] == 0){
                for(int j = i+1;j<n-cnt;++j){
                    nums[j-1] = nums[j];
                }
                
                cnt++;
            }
        }

        for(int i = 1;i<=cnt;++i){
            nums[n-i] = 0;
        }
    }
};
// @lc code=end

