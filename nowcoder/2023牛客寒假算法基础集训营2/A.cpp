#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int l1, r1;
    cin >> l1 >> r1;
    int l2, r2;
    cin >> l2 >> r2;

    int cnt = 0;
    for (int i = l1; i <= r1 && i >= l1; ++i) {
        int t = n - i;
        if (t >= l2 && t <= r2)
            cnt++;
    }

    cout << cnt << "\n";
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
