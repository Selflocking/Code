#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 1e3 + 5;

int n, v;
int V[mxN], W[mxN];
int f[mxN][mxN];

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> V[i] >> W[i];
    }

    // f[i][j]代表只考虑前i个物品下，背包总容量为j的情况下的最大价值。
    for (int i = 1; i <= n; ++i) {     // 故 1<=i<=n
        for (int j = 0; j <= v; ++j) { // 0<=j<=v
            if (j >= V[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - V[i]] + W[i]);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    cout << f[n][v]; // 故f[n][v]即最终答案
    return 0;
}
