/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;

        int sum = 0;
        int ans = 0;
        const int n = nums.size();
        for(int i = 0;i<n;++i){
            hash[sum]++;
            sum += nums[i];

            if(hash[sum-k]!=0){
                ans += hash[sum-k];
            }
        }
        return ans;
    }
};
// @lc code=end
int main(){
    auto cls = Solution();
    vector<int> nums{1,-1,0};
    int k = 0;
    cls.subarraySum(nums,k);
    return 0;
}
