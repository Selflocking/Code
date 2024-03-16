/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
// 循环加相向双指针 O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        const int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0;i<n-2;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;

            int l = i+1;
            int r = n-1;
            while(l<r){
                int s = nums[i]+nums[l]+nums[r];
                if(s<0){
                    l++;
                }else if(s>0){
                    r--;
                }else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    // 跳过重复的
                    int lc = nums[l];
                    int rc = nums[r];
                    while(l<r&&l<n&&nums[l]==lc) l++;
                    while(l<r&&r>i+1&&nums[r]==rc) r--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

