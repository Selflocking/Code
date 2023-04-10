#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
using ll = long long;
constexpr int mxN = 5e3 + 5;

ll w[mxN];
ll v[mxN];
ll f[mxN];
ll xuan[mxN];
ll buxuan[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i <= n; ++i) {
            if (i == x) continue;
            for (int j = m; j >= w[i]; --j) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        buxuan[x] = f[m];
        memset(f, 0, sizeof f);
    }
    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i <= n; ++i) {
            if (i == x) continue;
            for (int j = m - w[x]; j >= w[i]; --j) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        xuan[x] = f[m - w[x]] + v[x];
        memset(f, 0, sizeof f);
    }

    for (int i = 1; i <= n; ++i) {
        cout << max(0LL, buxuan[i] - xuan[i] + 1LL) << "\n";
    }
    return 0;
}
