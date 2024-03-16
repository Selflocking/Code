class Solution {
public:
    string minimizeStringValue(string s) {
        unordered_map<char,int> m;
        for(char c = 'a';c<='z';c++){
            m[c] = 0;
        }
        int cnt = 0;
        for(auto c:s){
            if(c!='?') m[c]++;
            else cnt++;
        }
        string tar;
        for(int i = 0;i<cnt;++i){
                int mi = 999999999;
                char t = 'a';
                for(char c = 'a';c<='z';c++){
                    if(m[c]<mi){
                        t = c;
                        mi = m[c];
                    }
                }
                tar+=t;
                m[t]++;
        }
        
        sort(tar.begin(),tar.end());
        
        int index = 0;
        for(auto &c:s){
            if(c=='?'){
                c = tar[index];
                index++;
            }
        }
        return s;
    }
};
