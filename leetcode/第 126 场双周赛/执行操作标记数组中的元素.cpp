class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        multimap<int,int> m;
        const int n = nums.size();
        long long sum = 0;
        
        for(int i = 0;i<n;++i){
            m.insert({nums[i],i});
            sum+=nums[i];
        }
        vector<bool> vis(n);
        
        vector<long long> ans;
        for(auto &q:queries){
            int index = q.front();
            int k = q.back();
            
            if(!vis[index]){
                auto range = m.equal_range(nums[index]);
                
                for(auto it = range.first;it!=range.second;++it){
                    if(it->second==index){
                        vis[index] = true;
                        sum-=nums[index];
                        m.erase(it);
                        break;
                    }
                }
            }
            
            while(k--&&!m.empty()){
                auto it = m.begin();
                sum-=nums[it->second];
                vis[it->second] = true;
                m.erase(it);
            }
            
            ans.push_back(sum);
        }
        return ans;
    }
};
