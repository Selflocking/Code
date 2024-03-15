/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
// // 从后往前处理，先去掉0,再最后补零
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         const int n = nums.size();
//         int cnt = 0;
//         for(int i = n-1;i>=0;--i){
//             if(nums[i] == 0){
//                 for(int j = i+1;j<n-cnt;++j){
//                     nums[j-1] = nums[j];
//                 }

//                 cnt++;
//             }
//         }

//         for(int i = 1;i<=cnt;++i){
//             nums[n-i] = 0;
//         }
//     }
// };
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int left = 0;
        int right = 0;
        /*
        如果数组没有0，那么快慢指针始终指向同一个位置，每个位置自己和自己交换；如果数组有0，快指针先走一步，此时慢指针对应的就是0，所以要交换。
        */
        while(right<n){
            if(nums[right]!=0){
                swap(nums[left],nums[right]);

                left++;
            }
            right++;
        }
    }
};
// @lc code=end

