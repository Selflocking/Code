#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 10;

int n;
int path[mxN];
bool st[mxN];
void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; ++i) {
            cout << path[i] << " \n"[i == n - 1];
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (!st[i]) {
                path[x] = i;
                st[i] = true;
                dfs(x + 1);
                st[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(0);
    return 0;
}
