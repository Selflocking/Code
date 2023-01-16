#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
constexpr int mxN = 5e2 + 5;

double f[mxN][mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= j; ++k) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + 1.0 * k / j);
            }
        }
    }

    printf("%.9f\n", f[n][m]);
    return 0;
}
