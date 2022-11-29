#include<iostream>
#include <numeric>

using namespace  std;
/*
想了很久，看了jiangly的代码才慢慢明白。
按照题目要求，类似于[1,2,3,4,5...]的数列是字典序最小的。
题目给了，n,x,先假设n!=x
并且ans[1] = x,ans[n] = 1;
其实就相当于从一个从1开始的递增数列。
变成如下内容：[x,2,3,4,5,,第x个 ,,1];
第x个位置是空的，同时多出了一个n。题目要求每一个数都是它下标的倍数（下标从1开始）
n肯定要放在某个位置，并且n一定是x的倍数这样的数列才能存在。
假设有第t个数是x的倍数，它能出现在ans[x],同时n是ans[t]的倍数。则n一定是x的倍数。
即在x-n之间找到一个数列，使得数列中每相邻的两个数成倍数关系。
*/

/*
输出小技巧：
        for(int i = 1;i<=n;++i){
            cout<<ans[i]<<" \n"[i==n];
        }
*/

const int mxN = 2e5+5;

int ans[mxN];

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,x;
        cin>>n>>x;
        if(n%x!=0){
            cout<<"-1\n";
            continue;
        }
        iota(ans+1, ans+n+1, 1);
        ans[1] = x;
        ans[n] = 1;

        for(int i = 2*x;i<=n;i+=x){
            if(n%i==0){
                ans[x] = i;
                x = i;
            }
        }

        for(int i = 1;i<=n;++i){
            cout<<ans[i]<<" \n"[i==n];
        }
    }
    return 0;
}