#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        res += abs(t);
    }
    cout << 2 * n * res << "\n";
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
