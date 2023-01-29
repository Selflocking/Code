#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

bool st[mxN];
int ans[mxN];
int n;

void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " \n"[i == n];
        }
        exit(0);
    }

    if (x - 2 > 0 && !st[x - 2]) {
        ans[x] = x - 2;
        st[x - 2] = 1;
        dfs(x + 1);
        st[x - 2] = 0;
    }
    if (x - 3 > 0 && !st[x - 3]) {
        ans[x] = x - 3;
        st[x - 3] = 1;
        dfs(x + 1);
        st[x - 3] = 0;
    }
    if (x + 2 <= n && !st[x + 2]) {
        ans[x] = x + 2;
        st[x + 2] = 1;
        dfs(x + 1);
        st[x + 2] = 0;
    }
    if (x + 3 <= n && !st[x + 3]) {
        ans[x] = x + 3;
        st[x + 3] = 1;
        dfs(x + 1);
        st[x + 3] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n < 4) {
        cout << -1 << "\n";
        return 0;
    }

    dfs(1);

    cout << -1 << "\n";
    return 0;
}
