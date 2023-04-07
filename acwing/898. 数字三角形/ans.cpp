#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 505;

int a[mxN][mxN];
int f[mxN][mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }

    f[1][1] = a[1][1];

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            // 需要考虑边界情况
            if (j == 1) {
                f[i][j] = f[i - 1][j] + a[i][j];
            } else if (j == i) {
                f[i][j] = f[i - 1][j - 1] + a[i][j];
            } else {
                f[i][j] = max(f[i - 1][j] + a[i][j], f[i - 1][j - 1] + a[i][j]);
            }
        }
    }
    int res = -99999999; // 注意应为负无穷
    for (int i = 1; i <= n; ++i) {
        if (f[n][i] > res) {
            res = f[n][i];
        }
    }
    cout << res << "\n";
    return 0;
}
