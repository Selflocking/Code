/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> st(128);

        const int n = s.size();
        if(n<=1) return n;

        int right = 0;
        int ans = 1;
        for(int left = 0;left<n;++left){
            if(left>0){
                st[s[left-1]] = false;
            }
            while(right<n&&!st[s[right]]){
                st[s[right]] = true;
                right++;
            }
            ans = max(ans,right-left);
        }
        return ans;
    }
};
// @lc code=end

int main(){
    string t = "pwwkew";
    auto s = Solution();
    std::cout<<s.lengthOfLongestSubstring(t)<<endl;
    return 0;
}