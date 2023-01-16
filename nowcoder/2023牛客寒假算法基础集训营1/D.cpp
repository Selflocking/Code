#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    int a = max(abs(xx - x), abs(xx - 0));
    int b = max(abs(yy - y), abs(yy - 0));
    int c = min(a, x);
    int d = min(b, y);
    int s = a * b + x * y;
    double ans = double(c * d) / (s - c * d);
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