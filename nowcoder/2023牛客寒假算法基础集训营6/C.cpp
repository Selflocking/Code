#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;
constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    // 1 4 5 8 9 10 7 6 3 2
    for (int i = 0; i < n / 2; ++i) {
        if (i % 2 == 0)
            a[i] = i * 2 + 1;
        else
            a[i] = (i + 1) * 2;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (i % 2 == 0) {
            a[n - i - 1] = a[i] + 1;
        } else {
            a[n - i - 1] = a[i] - 1;
        }
    }
    if (n % 2 == 1) a[n / 2] = n;

    string ans;
    for (int i = 0; i < n; ++i) {
        ans += to_string(a[i]) + " \n"[i == n - 1];
    }

    while (n > 1) {
        for (int i = 0; i + 1 < n; ++i) {
            a[i] = (a[i] + a[i + 1]) % MOD;
        }
        n--;
    }

    cout << a[0] << "\n";
    cout << ans;
    return 0;
}
