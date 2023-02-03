#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 4e5 + 5;

int cnt[mxN];
int pre[mxN];

void work(int x) {
    for (int j = 1; j * j <= x; ++j) {
        if (x % j == 0) {
            cnt[j]++;
            if (j * j != x) {
                cnt[x / j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        work(a[i]);
        pre[i] = cnt[a[i]];
    }

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            a.emplace_back(x);
            work(x);
            pre[a.size() - 1] = cnt[x];
        } else {
            cout << cnt[a[x]] - pre[x] << "\n";
        }
    }

    return 0;
}
