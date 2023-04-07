#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 105;

constexpr int MOD = 1e9 + 7;
int f[mxN][mxN][mxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    f[0][0][2] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= m; ++k) {
                if (i >= 1 && k % 2 == 0) {
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][k / 2]) % MOD;
                }
                if (j >= 1) {
                    f[i][j][k] = (f[i][j][k] + f[i][j - 1][k + 1]) % MOD;
                }
            }
        }
    }
    cout << f[n][m - 1][1] << "\n";
    return 0;
}
