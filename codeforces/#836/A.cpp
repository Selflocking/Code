#include<iostream>

using namespace std;
// 题目看了半天，没想到真的是这样。

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<s;
        for(int i = s.length()-1;i>=0;--i){
            cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}