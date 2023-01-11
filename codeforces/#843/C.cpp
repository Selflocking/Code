#include <bits/stdc++.h>
#include <math.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

inline long long lowbit(long long x) { return x & -x; }

void solve() {
    long long n, x;
    cin >> n >> x;
    long long m = n;
    while (n != x && m <= 5e18 && n != 0) {
        m = n + lowbit(n);
        // m = n + pow(2, m - 1); // 999999984306749440
        n &= m;
    }
    if (n == 0 && x != 0 || m > 5e18) {
        cout << -1 << "\n";
    } else {
        cout << m << "\n";
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