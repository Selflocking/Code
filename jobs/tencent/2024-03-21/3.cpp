#include <iostream>
#include <vector>
using namespace std;
const int mxN = 1e5 + 1;

vector<vector<int>> G(mxN);
bool st[mxN];

void dfs(int x, int &num) {
    st[x] = true;
    num++;
    for (auto j : G[x]) {
        if (st[j]) continue;

        dfs(j, num);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cnt = 0;
    vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            int num = 0;
            dfs(i, num);
            nums.push_back(num);
            cnt++;
        }
    }

    if (cnt > 2) {
        cout << 0 << "\n";
        return 0;
    }

    if (cnt == 2) {
        cout << nums[0] * nums[1] << "\n";
        return 0;
    }

    if (cnt < 2) {
        cout << 0 << "\n";
    }
    return 0;
}
