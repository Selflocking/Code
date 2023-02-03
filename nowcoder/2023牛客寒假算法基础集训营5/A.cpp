#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> sum(n + 1);

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    while (q--) {
        int k, x;
        cin >> k >> x;

        int t = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;

        cout << sum[t] - sum[max(0, t - k)] << "\n";
    }
    return 0;
}
