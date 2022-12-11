#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int N = 1e5 + 5;
vector<vector<int>> v;
bool vis[N];
int n;
queue<int> q;

int main() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            v[i].push_back(a);
            v[a].push_back(i);
        }
    }
    q.push(1);
    vis[1] = 1;
    int t;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        for (int i = 0; i < v[t].size(); ++i) {
            if (vis[v[t][i]] == 0) {
                q.push(v[t][i]);
                vis[v[t][i]] = 1;
            }
        }
    }
    cout << t;
    return 0;
}