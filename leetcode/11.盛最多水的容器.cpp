/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        int left = 0;
        int right = n-1;
        int ans = 0;

        /*
        从两边开始移动，始终移动高度较低的那个指针
        */
        while(left<right){
            int s = min(height[left],height[right])*(right-left);
            ans = max(ans,s);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end

