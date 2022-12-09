#include <algorithm>
#include <iostream>
#include <vector>
  
using namespace std;
  
constexpr long long MOD = 1e9 + 7;

int main() {
    long long  n;
    cin >> n;
    long long res = 0;
    long long ll = 0;
    for (long long i = 0; i < n; ++i) {
        ll = (i+ll)%MOD;
        res = (res + ll)%MOD;
    }

    // for(int i = 1;i<=n;++i){
    //     res = (res+(n-i)*i)%MOD;
    // }

    cout << res;
    // cout<<
    // 0 1 4     10    20  35
    // 0 1 1+2+1 4+3+2+1
    // 1 2 3    4
    // abcabc
    // abcabcabc
    // abcabcabcabc
    return 0;
}