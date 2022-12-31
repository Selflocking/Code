#include <bits/stdc++.h>
#include <cstring>

using namespace std;
constexpr int mxN = 1e2 + 5;
using pll = pair<int, int>;

int g[mxN][mxN];
int dist[mxN][mxN];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }
    queue<pll> q;
    memset(dist, -1, sizeof dist);

    q.push({1, 1});
    g[1][1] = 1;
    dist[1][1] = 0;

    while (!q.empty()) {
        pll it = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = it.first + dx[i];
            int y = it.second + dy[i];
            if (x <= n && x >= 1 && y <= m && y >= 1 && g[x][y] == 0 &&
                dist[x][y] == -1) {

                q.push({x, y});
                dist[x][y] = dist[it.first][it.second] + 1;
            }
        }
    }

    cout << dist[n][m] << "\n";
    return 0;
}
