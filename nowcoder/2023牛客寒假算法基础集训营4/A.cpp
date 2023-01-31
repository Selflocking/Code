#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << a << "\n";
    } else {
        if (pow(a, b) > pow(b, a)) {
            cout << a << "\n";
        } else if (pow(a, b) < pow(b, a)) {
            cout << b << "\n";
        } else {
            cout << min(a, b) << "\n";
        }
    }
    return 0;
}
