#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 1e5 + 5;
using path = pair<int, bool>;

vector<vector<path>> G(mxN);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (c != 'R') {
            G[u].push_back({v, false});
            G[v].push_back({u, false});
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (G[i].empty()) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
