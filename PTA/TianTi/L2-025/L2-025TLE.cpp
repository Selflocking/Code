#include <cstring>
#include <iostream>

using namespace std;
const int N = 1e4 + 5;
int map[N][N];
int vis[N];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    int k;
    cin >> k;
    while (k--) {
        memset(vis, 0, sizeof vis);
        int t;
        cin >> t;
        for (int i = 1; i <= t; ++i) {
            int a;
            cin >> a;
            vis[a] = 1;
        }
        int flag = 1;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 1) continue;
            for (int j = i; j <= n; ++j) {
                if (map[i][j] == 1 && vis[j] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) break;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}