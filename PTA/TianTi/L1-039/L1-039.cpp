#include "iostream"
#include "cmath"
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char str[1005][105];

int main(){
    int n;
    cin>>n;
    getchar();
    string s;
    getline(cin,s);
    memset(str, ' ', sizeof str);

    int x = ceil(1.0*s.size()/n);
    int y = n;
    int cnt = 0;
    for(int i = x-1;i>=0;--i){
        for(int j = 0;j<y&&cnt!=s.size();++j){
            str[i][j] = s[cnt++];
        }
    }
    for(int i = 0;i<y;++i){
        for(int j = 0;j<x;++j){
            cout<<str[j][i];
        }
        cout<<"\n";
    }
    return 0;
}