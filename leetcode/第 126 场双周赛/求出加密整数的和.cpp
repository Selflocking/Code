class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(auto i:nums){
            int cnt = 0;
            int mx = 0;
            while(i!=0){
                int t = i%10;
                mx = max(mx,t);
                cnt++;
                i/=10;
            }
            int item = 0;
            while(cnt--){
                item = item*10+mx;
            }
            ans += item;
        }
        return ans;
    }
};
