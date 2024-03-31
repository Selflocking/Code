#include <iostream>
#include <utility>
#include <vector>

using namespace std;
const int mxN = 1e3 + 1;
const string temp = "tencent";

pair<int, int> d[4] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

vector<vector<char>> G(mxN);
int cnt = 0;
int n, m;

void dfs(int x, int y, int s) {
    if (s >= temp.size()) {
        cnt++;
    }

    for (auto a : d) {
        auto xx = x + a.first;
        auto yy = y + a.second;
        if (xx < 0 || xx > n - 1 || yy < 0 || yy > m - 1) {
            continue;
        }

        if (G[xx][yy] == temp[s]) {
            dfs(xx, yy, s + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (auto &v : G) {
        v.resize(m + 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (G[i][j] == 't') {
                dfs(i, j, 1);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
