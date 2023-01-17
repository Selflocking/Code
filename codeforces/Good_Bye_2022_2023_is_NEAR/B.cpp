#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> res;
    for (int i = 0; i < n / 2; ++i) {
        res.push_back(n - i);
        res.push_back(i + 1);
    }
    if (n % 2 == 1) {
        res.push_back(n / 2 + 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " \n"[i == n - 1];
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
