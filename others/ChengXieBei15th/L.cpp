#include <bits/stdc++.h>
#include <cmath>

using namespace std;

inline int f(long long n, long long i) {
    return floor((double)n / i) + i - 1;
}

void solve() {
    long long n, l, r;
    cin >> n >> l >> r;

    if (l == r) {
        cout << r << "\n";
        return;
    }

    long long t = ceil(sqrt(n));

    if (r <= t) {
        long long bak = f(n, r);
        for (long long i = r; i >= l; --i) {
            if (f(n, i) > bak) {
                cout << i + 1 << "\n";
                break;
            }
        }
    } else if (l >= t) {
        cout << l << "\n";
    } else {
        long long bak = f(n, t);
        for (long long i = t; i >= l; --i) {
            if (f(n, i) > bak) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
