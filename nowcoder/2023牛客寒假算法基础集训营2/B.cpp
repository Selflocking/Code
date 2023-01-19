#include <algorithm>
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

    // [n-r1, n-l1]
    // [l2, r2]

    int cnt = 0;

    if (n - r1 >= l2) {
        if (n - l1 <= r2) {
            cnt = r1 - l1 + 1;
        } else {
            cnt = r2 - n + r1 + 1; //[l2 <= n-r1, r2<n-l1]
        }
    } else {
        if (n - l1 <= r2) {
            cnt = n - l1 - l2 + 1; //[ n-r1<l2, n-l1<=r2]
        } else {
            cnt = r2 - l2 + 1;
        }
    }

    cout << max(0, cnt) << "\n";
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