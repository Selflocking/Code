#include <iostream>
#include <vector>

using namespace std;
const int N = 1e4 + 5;
int vis[N];
int ori[N];
int n, m;
vector<int> v[N];

void check() {
    for (int i = 1; i <= n; ++i) {
        if (vis[i] > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        ori[a]++;
        ori[b]++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int k;
    cin >> k;
    while (k--) {
        for (int i = 1; i <= n; ++i)
            vis[i] = ori[i];
        int t;
        cin >> t;
        for (int i = 0; i < t; ++i) {
            int a;
            cin >> a;
            vis[a] = 0;
            for (int j = 0; j < v[a].size(); ++j)
                vis[v[a][j]]--;
        }
        check();
    }
    return 0;
}