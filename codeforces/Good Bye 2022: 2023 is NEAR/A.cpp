#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        auto te = min_element(a.begin(), a.end());
        *te = b[i];
    }
    // sort(a.begin(), a.end());
    long long res = 0;
    for (auto &it : a) {
        res += it;
    }
    cout << res << "\n";
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
