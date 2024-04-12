#include <iostream>
#include <vector>

using namespace std;
int n,q;
vector<int> arr;

int lower(int t){
    int l = 0;
    int r = n-1;
    while(l<r){
        int m = (l+r)/2;
        if (arr[m]>=t){
            r = m;
        }else{
            l = m + 1;
        }
    }
    if (arr[l]==t) return l;
    return -1;
}

int upper(int t){
    int l = 0;
    int r = n-1;
    while(l<r){
        // 如果 l = m, 计算m时需要加上1
        int m = (l+r)/2 + 1;
        if (arr[m]<=t){
            l = m;
        }else{
            r = m-1;
        }
    }
    if (arr[l]==t) return l;
    return -1;
}

int main() {
    cin>>n>>q;
    arr.resize(n);

    for(int i = 0;i<n;++i){
        cin>>arr[i];
    }

    while(q--){
        int t = 0;
        cin>>t;
        int l = lower(t);
        int u = upper(t);
        cout<<l<<" "<<min(u,n-1)<<"\n";
    }
    return 0;
}
