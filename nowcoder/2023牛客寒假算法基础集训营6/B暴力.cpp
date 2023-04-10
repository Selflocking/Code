#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] % a[i] == 0) b[i]++;
        }
    }

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            for (int i = 1; i <= n; ++i) {
                if (x % a[i] == 0) b[i]++;
            }

            a.emplace_back(x);
            b.emplace_back(0);
        } else {
            cout << b[x] << "\n";
        }
    }
    return 0;
}
