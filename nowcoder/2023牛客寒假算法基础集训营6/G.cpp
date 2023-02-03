#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> z;
    vector<int> f;
    int zero = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t > 0) {
            z.emplace_back(t);
        } else if (t < 0) {
            f.emplace_back(t);
        } else {
            zero++;
        }
    }

    sort(z.begin(), z.end(), greater<int>());
    sort(f.begin(), f.end());

    vector<int> res;

    for (int i = 1; i < z.size(); i += 2) {
        res.emplace_back(z[i] * z[i - 1]);
    }
    for (int i = 1; i < f.size(); i += 2) {
        res.emplace_back(f[i] * f[i - 1]);
    }

    if (z.size() % 2 == 1 && f.size() % 2 == 1 && zero == 0) {
        res.emplace_back(z.back() * f.back());
    }

    sort(res.begin(), res.end(), greater<int>());

    ll ans = 0;
    for (int a : res) {
        ans += a;
        k--;
        if (k == 0)
            break;
    }

    cout << ans << "\n";

    return 0;
}
