#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int a[mxN];
int b[mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (a[i] != b[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    if (i == n) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}