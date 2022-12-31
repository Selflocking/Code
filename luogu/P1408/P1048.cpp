// https://www.luogu.com.cn/problem/P1048
// 01 背包模板
#include <iostream>
using namespace std;
const int N = 105;
int n, m;
int v[N], w[N];
int f[N][1005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j >= v[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    int res = -1;
    for (int i = 0; i <= n; ++i) {
        res = max(res, f[m][i]);
    }

    cout << res;
}