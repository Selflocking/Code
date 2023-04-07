#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 505;

int f[mxN][mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> f[i][j];
        }
    }
    // 从下往上，不需要考虑边界情况。
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = max(f[i + 1][j] + f[i][j], f[i + 1][j + 1] + f[i][j]);
        }
    }
    cout << f[1][1] << "\n";
    return 0;
}
