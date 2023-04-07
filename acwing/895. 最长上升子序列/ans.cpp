#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e3 + 5;

int a[mxN];
int f[mxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = i - 1; j >= 1; --j) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (res < f[i]) {
            res = f[i];
        }
    }
    cout << res << "\n";
    return 0;
}
