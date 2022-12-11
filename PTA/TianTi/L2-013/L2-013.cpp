#include <cstring>
#include <iostream>

using namespace std;
bool vis[505];
int map[505][505];
int n, m;
void dfs(int x) {
    for (int i = 0; i < n; ++i) {
        if (map[x][i] && vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
        }
    }
}

int getCnt() {
    int res = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i);
            res++;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    int cnt = getCnt();
    int k;
    cin >> k;
    int tttttt = k;
    while (k--) {
        int t;
        cin >> t;
        for (int i = 0; i < n; ++i) {
            map[i][t] = 0;
            map[t][i] = 0;
        }
        int temp = getCnt();
        if (temp <= cnt + 1)
            cout << "City " << t << " is lost.\n";
        else
            cout << "Red Alert: City " << t << " is lost!\n";
        cnt = temp;
    }

    if (tttttt == n) cout << "Game Over.";
    return 0;
}