#include <iostream>

using namespace std;

const int mxN = 1e5 + 5;

int a[mxN];
int b[mxN];
int n;
int m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - a[i - 1];
    }

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }

    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + b[i];
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}