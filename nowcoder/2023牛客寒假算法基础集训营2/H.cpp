#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    map<int, int> a;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a[t]++;
    }

    vector<int> cnt(n + 1);
    vector<int> sum(n + 1);

    for (auto it : a) {
        cnt[it.second]++;
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] = cnt[i] * i;
    }

    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        int res = 0;
        res += sum[i];
        res += (i - 1) * (cnt[n] - cnt[i]);
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}