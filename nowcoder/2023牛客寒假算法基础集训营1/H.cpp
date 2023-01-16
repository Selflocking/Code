#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;
// 上、右、下、左
void solve() {
    int n;
    cin >> n;
    vector<string> pts(n * n);
    for (int i = 0; i < n * n - 1; ++i) {
        cin >> pts[i];
    }
    int ao[4] = {0, 0, 0, 0};
    int tu[4] = {0, 0, 0, 0};
    for (int i = 0; i < n * n - 1; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (pts[i][j] == '1') {
                ao[j]++;
            } else if (pts[i][j] == '2') {
                tu[j]++;
            }
        }
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < 4; ++i) {
        // ao[i]
        if (ao[i] > tu[(i + 2) % 4]) {
            y++;
        } else if (ao[i] < tu[(i + 2) % 4]) {
            x++;
        }
    }
    cout << 10 - x + y << "\n";
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
