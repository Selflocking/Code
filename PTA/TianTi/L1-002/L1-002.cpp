#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char ch;
    cin >> n >> ch;

    int t = sqrt((n + 1) / 2); // 一半的层数
    int k = 2 * t - 1; // 最上面一层的长度
    int ans = n - (t * t * 2 - 1); // 剩余的符号数量

    for (int i = 0; i < (k + 1) / 2; ++i) {
        for (int j = 0; j < i; ++j) cout << " ";
        for (int j = 0; j < k - i * 2; ++j) cout << ch;
        cout << "\n";
    }
    for (int i = (k + 1) / 2 - 2; i >= 0; --i) {
        for (int j = 0; j < i; ++j) cout << " ";
        for (int j = 0; j < k - i * 2; ++j) cout << ch;
        cout << "\n";
    }
    cout<<ans<<"\n";
    return 0;
}
