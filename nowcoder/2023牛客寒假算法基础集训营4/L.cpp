#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    long long va, vb, vc;
    cin >> va >> vb >> vc;
    va *= 2;
    vb *= 2;
    vc *= 2;

    long long lc = (va + vb - vc) / 2;
    long long la = vb - lc;
    long long lb = va - lc;

    if (la + lc <= lb || la + lb <= lc || lc + lb <= la) {
        cout << "No\n";
        return;
    }

    if (la % 2 != 0 || lb % 2 != 0 || lc % 2 != 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    cout << la / 2 << " " << lb / 2 << " " << lc / 2 << "\n";
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
