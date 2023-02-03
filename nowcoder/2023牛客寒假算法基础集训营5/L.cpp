#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> cmd(m);
    for (auto &[a, b] : cmd) {
        cin >> a >> b;
    }

    if (n <= 2) {
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> f(n + 1, 1e18);
    f[n] = 0;
    for (int i = n; i >= 2; --i) {
        for (auto &[a, b] : cmd) {
            if (b >= i)
                continue;
            ll t = i / b * b;
            f[t] = min(f[t], f[i] + a);
        }
    }

    ll ans = 1e18;
    for (int i = 2; i <= n; ++i) {
        if (f[i] < ans) {
            ans = f[i];
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
