/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include<iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = s.size();
        const int m = p.size();
        vector<int> res;
        unordered_map<char,int> hash;
        for(auto c:p){
            hash[c]++;
        }
        int r = 0;
        for(int i = 0;i<n;++i){
            while(r-i<m&&r<n){
                auto c = s[r];

                if(hash[c]>0){
                    hash[c]--;
                    r++;
                }else{
                    break;
                }
            }
            if(r-i>=m){
                res.push_back(i);
            }
            
            hash[s[i]]++;
        }
        return res;
    }
};
// @lc code=end
int main(){
    auto cls = Solution();
    auto s = "baa";
    auto p = "aa";
    cls.findAnagrams(s,p);
}
