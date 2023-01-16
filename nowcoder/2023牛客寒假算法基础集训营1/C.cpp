#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> papers(n);
    for (int i = 0; i < n; ++i) {
        cin >> papers[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (papers[i] >= 1) {
            ans++;
        }
    }
    cout << ans << "\n";
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
