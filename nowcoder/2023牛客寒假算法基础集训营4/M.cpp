#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 1 1 2 1 1 2 1 1 2
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0) {
            cout << "2 ";
        } else {
            cout << "1 ";
        }
    }
    cout << "\n";

    return 0;
}
