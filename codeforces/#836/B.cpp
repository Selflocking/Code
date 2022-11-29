#include <iostream>

using namespace std;
/*
看着难实际简单，如果n是奇数，输出n个1即可，如果n是偶数，输出n-2个2和1 3即可
峨峨，1 3.没看出来，我是跑出来的。=(

    for(int i = 1;i<=1e9;++i){
        for(int j = 1;i<=1e9;++j){
            if((i+j)%2!=0||j==i) continue;

            if((i^j)==(i+j)/2){
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }

*/
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 0; i < n - 2; ++i) { cout << 2 << " "; }
            cout << "1 3\n";
        } else {
            cout << 1;
            for (int i = 1; i < n; ++i) { cout << " " << 1; }
            cout << "\n";
        }
    }

    return 0;
}