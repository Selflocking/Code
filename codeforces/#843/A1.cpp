#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j + i < len; ++j) {
            string q = s.substr(0, 1);
            string mid = s.substr(i, j);
            string h = s.substr(i + j);
            if ((mid >= q && mid >= h) || (mid <= q && mid <= h)) {
                cout << q << " " << mid << " " << h << "\n";
                return;
            }
        }
    }

    cout << ":(\n";
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