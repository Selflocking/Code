#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 1e3 + 3;

int a[mxN][mxN];
int b[mxN][mxN];
int n, m, q;

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }
    }

    while (q--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        insert(a, b, c, d, e);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + b[i][j];
            cout << a[i][j] << " \n"[j == m];
        }
    }
    return 0;
}