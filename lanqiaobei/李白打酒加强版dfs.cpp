#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

constexpr int mxN = 105;
constexpr int MOD = 1e9 + 7;
int f[mxN][mxN][mxN];
int n, m;

int dfs(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;

    if (x > z) return 0;
    if (x == 1 && y == 0 && z == 1) return 1;
    if (f[x][y][z] != -1) return f[x][y][z];
    f[x][y][z] = (dfs(x * 2, y - 1, z) + dfs(x - 1, y, z - 1)) % MOD;
    return f[x][y][z];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(f, -1, sizeof f);
    cin >> n >> m;
    cout << dfs(2, n, m) << "\n";
    return 0;
}
