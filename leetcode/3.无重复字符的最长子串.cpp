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

        int left = 0;
        int right = 0;
        int ans = 1;
        while(right<n){
            auto l = s[left];
            auto r = s[right];
            if(!st[l]){
                st[l] = true;
            }
            if(!st[r]){
                st[r] =true;
                right++;
            }else{
                while(left<right && st[r]){
                    l = s[left];
                    st[l] = false;
                    left++;
                }
                st[r] = true;
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