/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> hashtable;
        for(auto i:nums){
          hashtable.insert(i);
        }

        int ans = 0;
        for(auto i:nums){
          if(!hashtable.count(i-1)){
            int cnt = 0;
            while(hashtable.count(i)){
              cnt++;
              i++;
            }
            ans = max(ans,cnt);
          }
        }
        return ans;
    }
};
// @lc code=end
