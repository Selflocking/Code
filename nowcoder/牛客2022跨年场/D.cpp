#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    while (c != 1) {
        if (c % a == 0) {
            c /= a;
            continue;
        } else if (c % b == 0) {
            c /= b;
            continue;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
