#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    map<int, int> s;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        arr[i].resize(k);
        for (int j = 0; j < k; ++j) {
            int t;
            cin >> arr[i][j];
            s[arr[i][j]]++;
        }
    }
    bool res = 0;

    for (int i = 0; i < n; ++i) {
        bool fl = 1;
        for (int j = 0; j < arr[i].size(); ++j) {
            if (s[arr[i][j]] <= 1) {
                fl = 0;
            }
        }
        if (fl == 1) {
            res = 1;
            break;
        }
    }

    if (res)
        cout << "Yes\n";
    else
        cout << "No\n";
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