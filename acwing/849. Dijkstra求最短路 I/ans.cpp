#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

constexpr int mxN = 2e5 + 5;
constexpr int INF = 0x3f3f3f3f;

// pair.first 距离
// pair.second 目标
using pii = pair<int, int>;
vector<pii> g[mxN];

int n, m;
int dist[mxN];
bool st[mxN];

void dijkstra() {
    // memset(dist, INF, sizeof dist);
    // fill(dist, dist + mxN, INF);
    fill_n(dist, mxN, INF);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    while (!heap.empty()) {
        auto it = heap.top();
        heap.pop();
        if (st[it.second]) continue;
        st[it.second] = true;
        for (auto i : g[it.second]) {
            if (dist[i.second] > dist[it.second] + i.first) {
                dist[i.second] = dist[it.second] + i.first;
                heap.push({dist[i.second], i.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[a].push_back({c, b});
    }
    dijkstra();
    if (dist[n] == INF) {
        cout << "-1\n";
    } else {
        cout << dist[n] << "\n";
    }
    return 0;
}
