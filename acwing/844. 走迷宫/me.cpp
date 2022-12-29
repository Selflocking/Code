#include <bits/stdc++.h>
#include <queue>

using namespace std;
constexpr int mxN = 1e2 + 5;

using pll = pair<int, int>;

int n, m;
int mp[mxN][mxN];
int res = 0;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }
    queue<pll> q;
    while (1) {
        q.push({1, 1});
        mp[1][1] = 1;
        int len = q.size();
        while (len--) {
            pll a = q.front();
            q.pop();
            if (a.first == n && a.second == m) {
                cout << res << "\n";
                return 0;
            }
            for (int i = 0; i < 4; ++i) {
                int x = a.first + dx[i];
                int y = a.second + dy[i];
                if (x <= n && x >= 1 && y <= m && y >= 1 && mp[x][y] == 0) {
                    q.push({x, y});
                    mp[x][y] = 1;
                }
            }
        }
        res++;
    }
    return 0;
}
