#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    int ans = -1;
    int A = 0;
    int B = 0;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            if (s[i] == '1') {
                A++;
            }
        } else {
            if (s[i] == '1') {
                B++;
            }
        }
        if (A > B + (5 - (i + 1) / 2)) {
            ans = i + 1;
            break;
        }
        if (A + (5 - (i + 2) / 2) < B) {
            ans = i + 1;
            break;
        }
    }
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
